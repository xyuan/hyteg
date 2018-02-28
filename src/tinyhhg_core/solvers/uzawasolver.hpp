#pragma once

#include "minressolver.hpp"

namespace hhg
{

template<class F, class O>
class UzawaSolver
{
public:

  enum class CycleType
  {
    VCYCLE,
    WCYCLE
  };

  UzawaSolver(const std::shared_ptr<PrimitiveStorage> & storage, uint_t minLevel, uint_t maxLevel)
    : minLevel_(minLevel), maxLevel_(maxLevel), coarseSolver_(storage, minLevel, minLevel),
      ax_("uzw_ax", storage, minLevel, maxLevel), tmp_("uzw_tmp", storage, minLevel, maxLevel)
  {
    // TODO: remove hardcoded parameters
    nuPre_ = 3;
    nuPost_ = 3;

    nuAdd_ = 2;

    zero_ = [](const hhg::Point3D&) { return 0.0; };
  }

  ~UzawaSolver()
  {
  }

  void solve(O& A, F& x, F& b, F& r, uint_t level, real_t tolerance, size_t maxiter, DoFType flag = All, CycleType cycleType = CycleType::VCYCLE, bool printInfo = false)
  {

    if (level == minLevel_) {
      coarseSolver_.solve(A, x, b, r, level, tolerance, maxiter, flag, false);
//      uzawaSmooth(A, x, b, r, level, flag);
    }
    else {
      // pre-smooth
      for (size_t i = 0; i < nuPre_; ++i)
      {
        uzawaSmooth(A, x, b, r, level, flag);
      }


      A.apply(x, ax_, level, flag);
      r.assign({1.0, -1.0}, { &b, &ax_ }, level, flag);

      // restrict
      r.restrict(level, flag);
      b.assign({1.0}, { &r }, level - 1, flag);
//      hhg::projectMean(b.p, ax_.p, level-1);

      x.interpolate(zero_, level-1);

      // solve on coarser level
      nuPre_ += nuAdd_;
      nuPost_ += nuAdd_;
      solve(A, x, b, r, level-1, tolerance, maxiter, flag, cycleType, printInfo);
      if (cycleType == CycleType::WCYCLE) {
        solve(A, x, b, r, level-1, tolerance, maxiter, flag, cycleType, printInfo);
      }
      nuPre_ -= nuAdd_;
      nuPost_ -= nuAdd_;

      // prolongate
      tmp_.assign({1.0}, { &x }, level, flag);
      x.prolongate(level-1, flag);
      x.add({1.0}, { &tmp_ }, level, flag);

      // post-smooth
      for (size_t i = 0; i < nuPost_; ++i)
      {
        uzawaSmooth(A, x, b, r, level, flag);
      }
    }

  }

private:

  void uzawaSmooth(O& A, F& x, F& b, F& r, uint_t level, DoFType flag) {

    A.divT_x.apply(x.p, r.u, level, flag, Replace);
    A.divT_y.apply(x.p, r.v, level, flag, Replace);

    r.u.assign({1.0, -1.0}, {&b.u, &r.u}, level, flag);
    r.v.assign({1.0, -1.0}, {&b.v, &r.v}, level, flag);

    A.A.smooth_gs(x.u, r.u, level, flag);
    A.A.smooth_gs(x.v, r.v, level, flag);

    A.div_x.apply(x.u, r.p, level, flag | DirichletBoundary, Replace);
    A.div_y.apply(x.v, r.p, level, flag | DirichletBoundary, Add);

    r.p.assign({1.0, -1.0}, {&b.p, &r.p}, level, flag | DirichletBoundary);

    A.pspg.smooth_sor(x.p, r.p, 0.3, level, flag | DirichletBoundary);
  }

  uint_t nuPre_;
  uint_t nuPost_;
  uint_t nuAdd_;

  uint_t minLevel_;
  uint_t maxLevel_;

  MinResSolver<F, O> coarseSolver_;
  F ax_;
  F tmp_;

  std::function<real_t(const hhg::Point3D&)> zero_;

};

}