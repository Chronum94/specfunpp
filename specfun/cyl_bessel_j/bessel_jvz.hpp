#pragma once

#include "impls/bessel_j_smallz.hpp"

template <class OrderType, class ArgType>
static inline ArgType bessel_cyl_jvz(OrderType v, ArgType z) {
  return bessel_j_smallz(v, z);
}
