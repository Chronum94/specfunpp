template <class T>
static inline T ipow(T base, int n) {
  if (n < 0) {
    base = 1.0 /base;
    n = - n;
  }
  if (n == 0) {
    return 1.0;
  } else if (n == 1) {
    return base;
  } else if (n % 2 == 0) {
    return ipow(base*base, n / 2);
  }
  return base * ipow(base * base, (n - 1) / 2);
}
