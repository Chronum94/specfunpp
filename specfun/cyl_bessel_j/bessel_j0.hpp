#pragma once

#include "impls/bessel_j_smallz.hpp"

template <class ArgType> static inline ArgType bessel_cyl_j0z(ArgType z) {
  return bessel_j_smallz(0.0, z);
}
