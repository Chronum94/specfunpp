#pragma once

#include "impls/bessel_j_smallz.hpp"
#include <cmath>
#include <complex>
template <class OrderType, class ArgType>
static inline ArgType bessel_cyl_jvz(OrderType v, ArgType z) {

  // double abs_z = std::sqrt(std::norm(z));

  // if (abs_z <= 4.0 || abs_z <= std::sqrt(std::norm(v)) - 2.0) {
    return bessel_j_smallz(v, z);


}
