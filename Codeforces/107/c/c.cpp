#include <map>
#include <iostream>

using namespace std;

map<long long, pair<bool, long long> > dp;

pair<bool, long long> solve(long long n) {
  if (dp.find(n) != dp.end()) return dp[n];
  bool prime = true;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      prime = false;
      pair<bool, long long> ret = solve(i);
      if (!ret.first) {
        dp[n] = make_pair(true, i);
        return dp[n];
      }
      ret = solve(n/i);
      if (!ret.first) {
        dp[n] = make_pair(true, n/i);
        return dp[n];
      }
    }
  }
  dp[n] = make_pair(prime, 0);
  return dp[n];
}

int main() {
  long long q;
  cin >> q;
  pair<bool, long long> ret = solve(q);
  if (ret.first)
    cout << "1 " << ret.second << endl;
  else
    cout << "2 " << endl;
  return 0;
}
