#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

#define mp make_pair

const int MOD = 1000000007LL;

int dp[105][3005][105];
map<int, set<pair<int,int> > > lengths;
map<int, vector<pair<int,int> > > LENGTHS;
int N, L;


int solve(int prev_w, int l, int prev_t) {
  if (dp[prev_w][l][prev_t] != 0) return dp[prev_w][l][prev_t];
  if (l == 0) return 1;
  if (l < 0) return 0;
  int ret = 0;
  if (l == L) {
    for (map<int, vector<pair<int, int> > >::iterator it = LENGTHS.begin(); it != LENGTHS.end(); ++it) {
      int length = it->first;
      vector<pair<int, int> > widths = it->second;
      for (vector<pair<int, int> >::iterator jt = widths.begin(); jt != widths.end(); ++jt) {
        int width = jt->first;
        int type = jt->second;
        if (type != prev_t) {
          ret = (ret + solve(width, l-length, type)) % MOD;
        }
      }
    }
  } else {
    vector<pair<int, int> > widths = LENGTHS[prev_w];
    for (vector<pair<int, int> >::iterator jt = widths.begin(); jt != widths.end(); ++jt) {
      int width = jt->first;
      int type = jt->second;
      if (type != prev_t) {
        ret = (ret + solve(width, l-prev_w, type)) % MOD;
      }
    }
  }
  dp[prev_w][l][prev_t] = ret;
  return ret;
}

int main() {
  int a, b;
  cin >> N >> L;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    lengths[a].insert(make_pair(b, i));
    lengths[b].insert(make_pair(a, i));
  }
  for (map<int, set<pair<int, int> > >::iterator it = lengths.begin(); it != lengths.end(); ++it) {
    int length = it->first;
    set<pair<int, int> > widths = it->second;
    for (set<pair<int, int> >:: iterator jt = widths.begin(); jt != widths.end(); ++jt) {
      LENGTHS[length].push_back(*jt);
    }
  }
  cout << solve(0, L, -1) << endl;
  return 0;
}
