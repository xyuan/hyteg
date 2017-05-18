#include <tinyhhg_core/tinyhhg.hpp>
#include <fmt/format.h>
#include <tinyhhg_core/likwidwrapper.hpp>

//using namespace walberla;
using walberla::uint_t;
using walberla::uint_c;

int main(int argc, char* argv[])
{
  LIKWID_MARKER_INIT;

  walberla::Environment walberlaEnv(argc, argv);
  walberla::MPIManager::instance()->useWorldComm();
  LIKWID_MARKER_THREADINIT;
  uint_t rk = uint_c(walberla::MPIManager::instance()->rank());

  if (walberlaEnv.config() == nullptr) {
    WALBERLA_ABORT("No parameter file was given");
  }

  auto parameters = walberlaEnv.config()->getOneBlock("Parameters");

  WALBERLA_LOG_INFO_ON_ROOT("TinyHHG FMG Test");


  hhg::Mesh mesh(parameters.getParameter<std::string>("mesh"));

  size_t minLevel = parameters.getParameter<size_t>("minlevel");
  size_t maxLevel = parameters.getParameter<size_t>("maxlevel");
  size_t nu_pre = parameters.getParameter<size_t>("nu_pre");
  size_t nu_post = parameters.getParameter<size_t>("nu_post");
  size_t outer = parameters.getParameter<size_t>("outer_iter");

  size_t coarse_maxiter = 100;
  double coarse_tolerance = 1e-6;
  double mg_tolerance = 1e-8;

  hhg::P1Function r("r", mesh, minLevel, maxLevel);
  hhg::P1Function b("b", mesh, minLevel, maxLevel);
  hhg::P1Function x("x", mesh, minLevel, maxLevel);
  hhg::P1Function x_exact("x_exact", mesh, minLevel, maxLevel);
  hhg::P1Function ax("ax", mesh, minLevel, maxLevel);
  hhg::P1Function tmp("tmp", mesh, minLevel, maxLevel);
  hhg::P1Function err("err", mesh, minLevel, maxLevel);

  hhg::P1LaplaceOperator A(mesh, minLevel, maxLevel);

  std::function<double(const hhg::Point3D&)> exact = [](const hhg::Point3D& xx) { return xx[0]*xx[0] - xx[1]*xx[1]; };
  std::function<double(const hhg::Point3D&)> rhs   = [](const hhg::Point3D&) { return 0.0; };
  std::function<double(const hhg::Point3D&)> zero  = [](const hhg::Point3D&) { return 0.0; };
  std::function<double(const hhg::Point3D&)> ones  = [](const hhg::Point3D&) { return 1.0; };

  x.interpolate(exact, maxLevel, hhg::DirichletBoundary);
  x_exact.interpolate(exact, maxLevel);

  tmp.interpolate(ones, maxLevel);
  double npoints = tmp.dot(tmp, maxLevel);

  auto solver = hhg::CGSolver<hhg::P1Function, hhg::P1LaplaceOperator>(mesh, minLevel, minLevel);

  if (rk == 0)
  {
    WALBERLA_LOG_INFO_ON_ROOT(fmt::format("Num dofs = {}", (size_t)npoints));
    WALBERLA_LOG_INFO_ON_ROOT("Starting V cycles");
    WALBERLA_LOG_INFO_ON_ROOT("iter  abs_res       rel_res       conv          L2-error");
  }

  double rel_res = 1.0;

  A.apply(x, ax, maxLevel, hhg::Inner);
  r.assign({1.0, -1.0}, {&b, &ax}, maxLevel, hhg::Inner);

  double begin_res = std::sqrt(r.dot(r, maxLevel, hhg::Inner));
  double abs_res_old = begin_res;

  err.assign({1.0, -1.0}, {&x, &x_exact}, maxLevel);
  double discr_l2_err = std::sqrt(err.dot(err, maxLevel) / npoints);

  if (rk == 0)
  {
    WALBERLA_LOG_INFO_ON_ROOT(fmt::format("{:3d}   {:e}  {:e}  {:e}  {:e}", 0, begin_res, rel_res, begin_res/abs_res_old, discr_l2_err));
  }

  std::function<void(size_t)> cscycle;

  cscycle = [&](size_t level)
  {
    if (level == minLevel)
    {
      // fmt::printf("Coarse solve...\n");
      solver.solve(A, x, b, r, minLevel, coarse_tolerance, coarse_maxiter, hhg::Inner, false);
    }
    else
    {
      // fmt::printf("Level %d...\n", level);

      // pre-smooth
      for (size_t i = 0; i < nu_pre; ++i)
      {
        A.smooth_gs(x, b, level, hhg::Inner);
      }

      A.apply(x, ax, level, hhg::Inner);
      r.assign({1.0, -1.0}, { &b, &ax }, level, hhg::Inner);

      // restrict
      r.restrict(level, hhg::Inner);
      b.assign({1.0}, { &r }, level - 1, hhg::Inner);

      x.interpolate(zero, level-1);

      cscycle(level-1);

      // prolongate
      tmp.assign({1.0}, { &x }, level, hhg::Inner);
      x.prolongate(level-1, hhg::Inner);
      x.add({1.0}, { &tmp }, level, hhg::Inner);

      // post-smooth
      for (size_t i = 0; i < nu_post; ++i)
      {
        A.smooth_gs(x, b, level, hhg::Inner);
      }
    }
  };

  LIKWID_MARKER_START("Compute");
  for (size_t i = 0; i < outer; ++i)
  {
    cscycle(maxLevel);
    A.apply(x, ax, maxLevel, hhg::Inner);
    r.assign({1.0, -1.0}, { &b, &ax }, maxLevel, hhg::Inner);
    double abs_res = std::sqrt(r.dot(r, maxLevel, hhg::Inner));
    rel_res = abs_res / begin_res;
    err.assign({1.0, -1.0}, { &x, &x_exact }, maxLevel);
    discr_l2_err = std::sqrt(err.dot(err, maxLevel) / npoints);

    if (rk == 0)
    {
      WALBERLA_LOG_INFO_ON_ROOT(fmt::format("{:3d}   {:e}  {:e}  {:e}  {:e}", i+1, abs_res, rel_res, abs_res/abs_res_old, discr_l2_err));
    }

    abs_res_old = abs_res;

    if (rel_res < mg_tolerance)
    {
      break;
    }
  }
  LIKWID_MARKER_STOP("Compute");

  // hhg::VTKWriter({ &x }, maxLevel, "../output", "test");
  LIKWID_MARKER_CLOSE;
  return EXIT_SUCCESS;
}
