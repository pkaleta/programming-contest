#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<long long> p(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &p[i]);

  vector<long long> dp(k+1, 0);
  dp[1] = p[0];
  long long mx = p[0];
  vector<long long> tmp(k+1, 0);

  for (int i = 1; i < n; ++i) {
    tmp[0] = mx;
    for (int j = 1; j <= k; ++j)
      tmp[j] = p[i] + dp[j-1];
    for (int j = 0; j <= k; ++j) {
      mx = max(mx, tmp[j]);
      dp[j] = tmp[j];
    }
  }
  long long ret = 0;
  for (int i = 0; i <= k; ++i)
    ret = max(ret, dp[i]);
  printf("%lld\n", ret);
  return 0;
}
