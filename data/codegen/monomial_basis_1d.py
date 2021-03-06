#!/usr/bin/env python3

import numpy as np
import scipy.special
from sympy import *
from enum import Enum
import sys

x = symbols('x')

DEGREE = 7

monomials = []

def pow_to_mul(expr):
  """
  Convert integer powers in an expression to Muls, like a**2 => a*a.
  """
  pows = list(expr.atoms(Pow))
  if any(not e.is_Integer for b, e in (i.as_base_exp() for i in pows)):

      raise ValueError("A power contains a non-integer exponent")
  repl = zip(pows, (Mul(*[b]*e,evaluate=False) for b,e in (i.as_base_exp() for i in pows)))
  return expr.subs(repl)

for d in range(DEGREE+1):
  monomials.append(pow_to_mul(x**d))

num_coefficients = len(monomials)

# Generate code
x.name = 'x'

def generate(name):
  print('class {} {{'.format(name))
  print('public:')

  print('  static real_t eval(uint_t basis, real_t x) {')

  print('    switch(basis) {')

  for i in range(num_coefficients):
    print('        case {}:'.format(i))

    poly = monomials[i]

    print('        return {};'.format(ccode(poly)))

  print('      default:')
  print('        WALBERLA_ABORT("Polynomial basis " << basis << " was not generated");')

  print('    }')
  print('  }')

  print('};\n')


print('#pragma once\n')
print('// This file was generated by the monomial_basis_1d.py Python script')
print('// Do not edit it by hand\n')
print('namespace hyteg {\n')

generate('MonomialBasis1D')

print('}')
