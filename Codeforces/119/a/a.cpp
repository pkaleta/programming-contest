#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int ret = 0;
  for (int i = 0; i <= n; ++i) {
    if (a * i > n) break;
    for (int j = 0; j <= n; ++j) {
      if (a * i + b * j > n) break;
      int left = n - (a * i + b * j);
      if (left % c == 0) {
        int k = left / c;
        ret = max(ret, i + j + k);
      }
    }
  }
  cout << ret << endl;
  return 0;
}
