#pragma once

#include "../../mathutils/ipow.hpp"
#include <cmath>

template <class OrderType, class ArgType>
ArgType bessel_j_smallz(const OrderType v, const ArgType z) {
  using std::pow;
  using std::tgamma;

  ArgType zhalf = z / 2.0;
  ArgType result = 0.0;
  double factorial_term = 1.0;
  double gamma_term = tgamma(v + 1);

  result += 1.0 / gamma_term;

  gamma_term *= v + 1;
  result -= ipow(zhalf, 2) / gamma_term;

  for (int k = 2; k <= 20; k += 2) {
    factorial_term *= k;
    gamma_term *= v + k;
    result += ipow(zhalf, 2 * k) / (factorial_term * gamma_term);

    factorial_term *= k + 1;
    gamma_term *= v + k + 1;
    result -= ipow(zhalf, 2 * k + 2) / (factorial_term * gamma_term);
  }
  return result * pow(zhalf, v);
}
