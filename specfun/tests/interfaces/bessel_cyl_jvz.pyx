# distutils: language = c++
import numpy as np
cimport cython

ctypedef fused ArgType:
  double
  double complex
  # float
  # float complex

ctypedef fused OrderType:
  double
  float

cdef extern from "../../cyl_bessel_j/bessel_jvz.hpp":
  double bessel_cyl_jvz(double, double)
  double complex bessel_cyl_jvz(double, double complex)


cpdef jvx(double v , double x):
  return bessel_cyl_jvz(v, x)

@cython.boundscheck(False)
@cython.wraparound(False)
cpdef jvxv(double v , double[:] x):
  out = np.zeros_like(x)
  cdef int i = 0
  for i in range(0, out.shape[0]):
    out[i] = bessel_cyl_jvz(v, x[i])
  return out

cpdef jvz(double v , double complex z):
  return bessel_cyl_jvz(v, z)
