#include <cstdio>

using namespace std;

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    if (n == m)
      printf("0.00\n");
    else {
      double ret = 0.0f;
      int j = 1;
      for (int i = m+1; i <= n; ++i, ++j)
        ret += (double)(j + ((1 << (n+1)) - 2)) / (double)(1 << j);
      ret += (double)(n-m)/(double)(1 << (n-m));
      printf("%.2lf\n", ret);
    }
  }
  return 0;
}
