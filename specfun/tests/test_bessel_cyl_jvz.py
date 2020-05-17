from hypothesis import given, settings
import hypothesis.strategies as st

from mpmath import besselj
import numpy as np
import bessel as jvz


@given(st.floats(min_value = 0.0, max_value = 200.0, allow_nan=False),
st.floats(min_value = 0.0, max_value = 10.0, allow_nan=False))
@settings(max_examples=100)
def test_jvx_smallx(v, z):
    assert np.isclose(jvz.jvx(v, z), float(besselj(v, z)), rtol=5e-15)

@given(st.floats(min_value = 0.0, max_value = 200.0, allow_nan=False),
st.complex_numbers(min_magnitude = 0, max_magnitude=8))
@settings(max_examples=1000)
def test_jvz_smallz(v, z):
    test = jvz.jvz(v, z)
    ref = np.complex128(besselj(v, z))
    # assert np.isclose(test.real, ref.real, rtol=5e-13)
    assert np.isclose(test.imag, ref.imag, rtol=5e-13, atol=1e-15)

# test_jvz_smallz(1.5915713191816398e-09, (-2.2204460492503135e-15-0j))
