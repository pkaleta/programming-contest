#include <iostream>

using namespace std;

int main() {
  int w, h;
  cin >> w >> h;
  long long ret = 0;

  for (int y = 1; y < h; ++y) {
    for (int x = 1; x < w; ++x) {
      int half_height = min(h - y, y);
      int half_weight = min(w - x, x);
      //      cout << y << " " << x << half_weight << " " << half_height << endl;
      if (half_height > 0 && half_weight > 0)
        ret += half_weight * half_height;
    }
  }
  cout << ret << endl;
}
