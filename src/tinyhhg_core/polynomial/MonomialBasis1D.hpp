#pragma once

// This file was generated by the monomial_basis_1d.py Python script
// Do not edit it by hand

namespace hhg {

class MonomialBasis1D {
public:
  static real_t eval(uint_t basis, real_t x) {
    switch(basis) {
      case 0:
        return 1;
      case 1:
        return x;
      case 2:
        return x*x;
      case 3:
        return x*x*x;
      case 4:
        return x*x*x*x;
      case 5:
        return x*x*x*x*x;
      case 6:
        return x*x*x*x*x*x;
      case 7:
        return x*x*x*x*x*x*x;
      default:
        WALBERLA_ABORT("Polynomial basis " << basis << " was not generated");
    }
  }
};

}