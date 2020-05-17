#pragma once

#include "../../mathutils/ipow.hpp"
#include <cmath>
#include <type_traits>
template <class OrderType, class ArgType>
ArgType bessel_j_smallz(OrderType v, const ArgType z) {
  using std::pow;
  using std::tgamma;

  if (z == 0.0 && v == 0.0) {
    return 1;
  }
  ArgType zhalf = z / 2.0;
  ArgType result = 0.0;
  double factorial_term = 1.0;
  double gamma_term = tgamma(v + 1);

  result += 1.0 / gamma_term;

  gamma_term *= v + 1;
  ArgType zhalf_squared = zhalf * zhalf;
  result -= zhalf_squared / gamma_term;
  ArgType zhalf_powered = zhalf_squared;

  for (int k = 2; k <= 20; k += 2) {
    factorial_term *= k;
    gamma_term *= v + k;
    zhalf_powered *= zhalf_squared;
    result += zhalf_powered / (factorial_term * gamma_term);

    factorial_term *= k + 1;
    gamma_term *= v + k + 1;
    zhalf_powered *= zhalf_squared;
    result -= zhalf_powered / (factorial_term * gamma_term);
  }
  return result * pow(zhalf, v);
}
