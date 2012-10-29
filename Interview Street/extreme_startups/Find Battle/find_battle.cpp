#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
  int id;
  int x;
  int y;
};

int n, q;
vector<Point> points;

int dist(Point& p1, Point& p2) {
  int xx = abs(p1.x - p2.x);
  int yy = abs(p1.y - p2.y);
  return xx*xx + yy*yy;
}

Point get_closest(Point& p, Point& p1, Point& p2) {
  int d1 = dist(p, p1);
  int d2 = dist(p, p2);
  if (d1 == d2) {
    if (p1.id > p2.id) return p1;
    else return p2;
  }
  if (d1 < d2) return p1;
  else return p2;
}

Point closest(Point& p, int l, int r, vector<Point> points) {
  if (l == r) return points[l];
  if (l+1 == r) return get_closest(p, points[l], points[r]);
  int m = (l + r ) / 2;
  Point p1 = closest(p, l, m, points);
  Point p2 = closest(p, m+1, r, points);
  return get_closest(p, p1, p2);
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    Point p = Point();
    cin >> p.id >> p.x >> p.y;
    points.push_back(p);
  }
  for (int i = 0; i < q; ++i) {
    Point p = Point();
    cin >> p.x >> p.y;
    Point p1 = closest(p, 0, points.size()-1, points);
    vector<Point> points2;
    for (int i = 0; i < points.size(); ++i) {
      if (p1.id != points[i].id) {
        points2.push_back(points[i]);
      }
    }
    Point p2 = closest(p, 0, points2.size()-1, points2);
    cout << p1.id << " " << p2.id << endl;
  }
  return 0;
}
