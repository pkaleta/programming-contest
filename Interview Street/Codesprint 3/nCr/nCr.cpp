#include <cstdio>

const long long MOD = 142857;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long solve(long long n, long long r) {
  if (r > n - r)
    r = n - r;

  long long num = 1;
  long long den = 1;
  for (long long i = n-r+1, j = 1; i <= n; ++i, ++j) {
    num *= i;
    den *= j;
    long long g = gcd(num, den) % MOD;
    num = (num / g) % MOD;
    den = (den / g) % MOD;
  }
  return (num / den) % MOD;
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    long long n, r;
    scanf("%lld%lld", &n, &r);
    printf("%lld\n", solve(n, r));
  }
  return 0;
}
