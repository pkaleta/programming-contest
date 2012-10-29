#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, int> > r;
map<int, int> m;
int cnt;
vector<vector<pair<int, int> > > res;
int n;

int main() {
  cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    m[x]++;
  }
  for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i) {
    r.push_back(make_pair(i->second, i->first));
  }
  make_heap(r.begin(), r.end());
  while (r.size() >= 3) {
    vector<pair<int, int> > s;
    for (int i = 0; i < 3; ++i) {
      pop_heap(r.begin(), r.end());
      pair<int, int> top = r[r.size()-1];
      s.push_back(top);
      r.pop_back();
    }
    res.push_back(s);
    cnt++;

    for (int i = 0; i < 3; ++i) {
      if (s[i].first - 1 > 0) {
        r.push_back(make_pair(s[i].first-1, s[i].second));
        push_heap(r.begin(), r.end());
      }
    }
  }

  cout << cnt << endl;
  for (int i = 0; i < res.size(); ++i) {
    vector<int> s;
    for (int j = 0; j < 3; ++j) {
      s.push_back(res[i][j].second);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < 3; ++i) {
      cout << s[3-i-1] << " ";
    }
    cout << endl;
  }
}
