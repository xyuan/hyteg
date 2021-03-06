def parameter_file_01_cube(scenario: int, max_level: int, num_edges_per_side: int, db_file: str, timing_file: str,
                           pre_smooth: int, post_smooth: int, inc_smooth: int, fmg_inner_iterations: int, num_cycles: int,
                           **kwargs):
    return f"""Parameters
{{
  discretization p2p1;

  minLevel 0;
  maxLevel {max_level};

  numEdgesPerSide {num_edges_per_side};

  scenario {scenario};
  domainInfoOnly false;

  vtk false;
  dbFile {db_file};
  timingFile {timing_file};

  preSmooth {pre_smooth};
  postSmooth {post_smooth};
  incSmooth {inc_smooth};
  fmgInnerIterations {fmg_inner_iterations};
  numCycles {num_cycles};
  absoluteResidualTolerance 1e-12;

  numGSVelocity 3;
  symmGSVelocity false;

  estimateOmega false;
  omega 0.2;
  omegaEstimationLevel 5;
  omegaEstimationIterations 100;

  coarseGridSolverType 1;
  maxIterations 10000;
  coarseGridAbsoluteResidualTolerance 1e-12;
}}
"""


def job_file_hawk(job_name: str, binary_name: str, num_nodes: int, num_omp_threads_per_mpi_proc: int, walltime: str, total_num_procs: int, paramfile_name: str,
                  path: str, **kwargs):
    return f"""#!/bin/bash
#PBS -N {job_name}
#PBS -l select={num_nodes}:node_type=rome:mpiprocs={num_omp_threads_per_mpi_proc}
#PBS -l walltime={walltime}
#PBS -m abe
#PBS -M dominik.thoennes@fau.de

export MPI_LAUNCH_TIMEOUT=1000
export MPI_IB_CONGESTED=1

module load gcc
module load mpt
module load cmake
module load petsc
module list

cd $PBS_O_WORKDIR
cd ..
pwd
ls -lha

mpirun -np {total_num_procs} omplace -c 0-128:st={int(128 / num_omp_threads_per_mpi_proc)} {path}{binary_name} {path}hawk/{paramfile_name}
"""


def job_file_supermuc(job_name: str, binary_name: str, num_nodes: int, num_mpi_procs_per_node: int, num_omp_threads_per_mpi_proc: int, walltime: str, paramfile_name: str, **kwargs):
    petsc_detail_string = "-ksp_view -ksp_monitor -log_view -mat_mumps_icntl_4 2"

    def partition(num_nodes):
        if num_nodes <= 16:
            return "micro"
        elif num_nodes <= 768:
            return "general"
        elif num_nodes <= 3072:
            return "large"

    constraint = ""
    if num_nodes <= 792:
        constraint = "#SBATCH --constraint=[i01|i02|i03|i04|i05|i06|i07|i08]"

    return f"""#!/bin/bash
# Job Name and Files (also --job-name)
#SBATCH -J {job_name}
#Output and error (also --output, --error):
#SBATCH -o ./%x.%j.out
#SBATCH -e ./%x.%j.err
#Initial working directory (also --chdir):
#SBATCH -D ./
#Notification and type
#SBATCH --mail-type=END
#SBATCH --mail-user=nils.kohl@fau.de
# Wall clock limit:
#SBATCH --time={walltime}
#SBATCH --no-requeue
#Setup of execution environment
#SBATCH --export=NONE
#SBATCH --get-user-env
#SBATCH --account=pr86ma
 
#SBATCH --ear=off
#SBATCH --partition={partition(num_nodes)}
#Number of nodes and MPI tasks per node:
#SBATCH --nodes={num_nodes}
#SBATCH --ntasks-per-node={num_mpi_procs_per_node}
{constraint}

cd ..
pwd
ls -lha

source load_modules_supermuc.sh

export OMP_NUM_THREADS={num_omp_threads_per_mpi_proc}

export I_MPI_PIN_CELL=core
export I_MPI_PIN_DOMAIN=omp:compact

module list

#Run the program:
mpiexec -n $SLURM_NTASKS ./{binary_name} supermuc/{paramfile_name} {petsc_detail_string}
"""
