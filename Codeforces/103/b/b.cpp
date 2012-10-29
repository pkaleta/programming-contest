#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool inside(int x, int y, int xs, int ys, int r) {
  return (x-xs)*(x-xs)+(y-ys)*(y-ys) <= r * r;
}

int main() {
  int n, x, y, r;
  int xa1, ya1, xb1, yb1;
  int xa, ya, xb, yb;
  vector<pair<int, int> > points;

  cin >> xa1 >> ya1 >> xb1 >> yb1;
  xa = min(xa1, xb1);
  ya = min(ya1, yb1);
  xb = max(xa1, xb1);
  yb = max(ya1, yb1);

  cin >> n;

  for (int i = xa; i <= xb; ++i) {
    points.push_back(make_pair(i, ya));
    points.push_back(make_pair(i, yb));
  }
  for (int i = ya + 1; i < yb; ++i) {
    points.push_back(make_pair(xa, i));
    points.push_back(make_pair(xb, i));
  }

  vector<bool> used(points.size());
  for (int i = 0; i < used.size(); ++i)
    used[i] = false;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> r;
    for (int j = 0; j < points.size(); ++j) {
      if (inside(points[j].first, points[j].second, x, y, r)) {
        used[j] = true;
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < used.size(); ++i)
    if (used[i] == false) ++ret;

  cout << ret << endl;
  return 0;
}
