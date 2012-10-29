#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_S = 10000005;
map<int, int> values;

void precalc() {
  vector<int> prev_row;
  vector<int> cur_row;
  for (int i = 1; i <= MAX_S; ++i) {
    prev_row.push_back(i);
    values[i] = i;
  }
  for (int r = 2; r < MAX_S; ++r) {
    cur_row.clear();
    cur_row.push_back(1);
    for (int c = 1; c < MAX_S; ++c) {
      if (prev_row[c] > MAX_S || cur_row[c-1] > MAX_S)
        break;
      int val = prev_row[c] + cur_row[c-1];
      if (val <= MAX_S && r + c < values[val]) {
        values[val] = r + c;
      }
      cur_row.push_back(val);
      if (val > MAX_S)
        break;
    }
    // for (int i = 0; i < cur_row.size(); ++i) {
    //   cout << cur_row[i] << " ";
    // }
    // cout << endl;
    prev_row = cur_row;
  }
}

vector<pair<int, int> > divisors(int s) {
  vector<pair<int, int> > ret;
  ret.push_back(make_pair(1, s));
  for (int i = 2; i * i <= s; ++i) {
    if (s % i == 0) {
      ret.push_back(make_pair(i, s / i));
    }
  }
  return ret;
}

int solve(int s) {
  int ret = 1 << 30;
  vector<pair<int, int> > divs = divisors(s);
  for (int i = 0; i < divs.size(); ++i) {
    int a = divs[i].first;
    int b = divs[i].second;
    ret = min(ret, values[a] + values[b]);
  }
  return ret;
}

int main() {
  int R, s;
  precalc();
  scanf("%d", &R);
  for (int r = 1; r <= R; ++r) {
    scanf("%d", &s);
    printf("Case #%d: %d\n", r, solve(s));
  }
  return 0;
}
