#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>

using namespace std;


struct Rect {
  int x1, y1, x2, y2;
  int count;

  Rect(int _x1, int _y1, int _x2, int _y2, int c) : x1(_x1), x2(_x2), y1(_y1), y2(_y2), count(c) {}

  long long area() {
    return ((long long)x2 - (long long)x1) * ((long long)y2 - (long long)y1);
  }
};

Rect* intersect(Rect* r1, Rect* r2) {
  if (r1->x1 < r2->x2 && r1->x2 > r2->x1 &&
      r1->y1 < r2->y2 && r1->y2 > r2->y1) {
    return new Rect(max(r1->x1, r2->x1),
                    max(r1->y1, r2->y1),
                    min(r1->x2, r2->x2),
                    min(r1->y2, r2->y2),
                    r1->count + r2->count);
  } else {
    return NULL;
  }
}


void print(Rect* r) {
  cout << r->x1 << ", " << r->y1 << ", " << r->x2 << ", " << r->y2 << " count: " << r->count << " area: (" << r->area() << ")" << endl;
}


bool exist(Rect* rect, vector<Rect*>& rects) {
  for (int i = 0; i < rects.size(); ++i) {
    if (rects[i]->x1 == rect->x1 &&
        rects[i]->y1 == rect->y1 &&
        rects[i]->x2 == rect->x2 &&
        rects[i]->y2 == rect->y2 &&
        rects[i]->count == rect->count)
      return true;
  }
  return false;
}


void insert(Rect* rect, vector<Rect*>& rects) {
  if (!exist(rect, rects))
    rects.push_back(rect);
}


int main() {
  int n;
  int x1, y1, x2, y2;
  vector<Rect*> rects;

  scanf("%d", &n);
  vector<Rect*> tmp;

  for (int i = 1; i <= n; ++i) {
    Rect* rect;
    tmp.clear();

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    rect = new Rect(x1, y1, x2, y2, 1);

    if (rect->count >= i - 1)
      insert(rect, tmp);

    for (int j = 0; j < rects.size(); ++j) {
      if (rects[j]->count >= i - 1)
        insert(rects[j], tmp);

      Rect* new_rect = intersect(rects[j], rect);
      if (new_rect && new_rect->count >= i - 1)
        insert(new_rect, tmp);
    }

    rects = tmp;
    // cout << "**********" << rects.size() << endl;
    // for (int j = 0; j < rects.size(); ++j) {
    //   print(rects[j]);
    // }
  }

  //cout << "**********" << rects.size() << endl;

  long long area = 0LL;
  int n_subsets = 1 << rects.size();

  for (int i = 0; i < n_subsets; ++i) {
    int n = i;
    long long cur_area = 0LL;
    int subset_count = 0;
    bool first = true;
    Rect* cur_rect = NULL;


    int j = 0;
    while (n) {
      if (n & 1) {
        ++subset_count;
        if (first) {
          cur_rect = rects[j];
          first = false;
        } else {
          if (cur_rect)
            cur_rect = intersect(cur_rect, rects[j]);
        }
      }
      ++j;
      n >>= 1;
    }

    if (cur_rect) {
      cur_area = cur_rect->area();
      if (subset_count & 1)
        area += cur_area;
      else
        area -= cur_area;
    }
  }

  printf("%lld\n", area);

  return 0;
}
