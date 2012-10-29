#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  double ret = 1.0f;

  for (int k = 2; k <= n; ++k)
    ret = (ret * (double)(n+k) / (double)(k)) % MOD;

  printf("%lf\n", ret);
  return 0;
}
