#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> p;

int solve(string& s, int start) {
  if (start == s.size()-1)
    return 0;

  p.clear();
  p.push_back(0);
  p.push_back(0);
  int t = 0;
  for (int j = 2; j < s.size(); ++j) {
    while (t > 0 && s[start+t+1] != s[start+j])
      t = p[t];
    if (s[start+t+1] == s[start+j])
      t += 1;
    p.push_back(t);
    if (j % 2 == 0 && p[j] == j/2) {
      s[start+j] = '*';
      return 2 + solve(s, start+j);
    }
  }
}

int main() {
  string s;
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    s = "*" + s;
    cout << solve(s, 0) << endl;
  }
  return 0;
}
