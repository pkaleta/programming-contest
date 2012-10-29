#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  int x;
  vector<vector<int> > v;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    vector<int> line;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &x);
      line.push_back(x);
    }
    v.push_back(line);
  }
  vector<int> p;
  vector<int> bestp;
  int bestc = 0;
  for (int i = 0; i < n; ++i)
    p.push_back(i);
  int reps = 0;
  while (next_permutation(p.begin(), p.end()) && reps <= 3000000) {
    int count = 0;
    for (int i = 0; i < n-1; ++i)
      count += v[p[i]][p[i+1]];
    if (count > bestc) {
      bestc = count;
      bestp = p;
    }
    ++reps;
  }
  for (int i = 0; i < n; ++i)
    printf("%d ", bestp[i]);
  printf("\n");
  return 0;
}
