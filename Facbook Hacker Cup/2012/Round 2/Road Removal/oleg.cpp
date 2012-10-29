#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

using namespace std;

vector <int> *g;
int *color, *map, edge_count, vertex_count;

void dfs( int u, int cc ) {
  color[u] = 1, vertex_count++;
  map[u] = cc;
  for (int i = 0; i < (int)g[u].size(); i++) {
    edge_count++;
    if (color[g[u][i]] == 0)
      dfs(g[u][i], cc);
  }
}

int main() {
  int test_count;
  assert(scanf("%d", &test_count) == 1);
  for (int test = 1; test <= test_count; test++) {
    int n, m, k;
    assert(scanf("%d%d%d", &n, &m, &k) == 3);
    int a[m], b[m];
    for (int i = 0; i < m; i++)
      assert(scanf("%d%d", &a[i], &b[i]) == 2);
    vector <int> g0[n]; g = g0;
    for (int i = 0; i < m; i++)
      if (a[i] >= k && b[i] >= k)
        g0[a[i]].push_back(b[i]), g0[b[i]].push_back(a[i]);
    // fprintf(stderr, "mapping..\n");
    int m0[n], t = 0; map = m0;
    int c0[n]; color = c0;
    memset(color, 0, sizeof(color[0]) * n);
    for (int i = 0; i < n; i++) {
      if (color[i] != 0)
        continue;
      dfs(i, t++);
    }
    // for (int i = 0; i < n; i++)
    //   fprintf(stderr, "map: %d -> %d\n", i, m0[i]);
    vector <int> g1[t]; g = g1;
    for (int i = 0; i < m; i++) {
      int _a = m0[a[i]];
      int _b = m0[b[i]];
      if (_a == _b)
        continue;
      // fprintf(stderr, "edge: (%d,%d)\n", _a, _b);
      g1[_a].push_back(_b);
      g1[_b].push_back(_a);
    }
    // fprintf(stderr, "calc..\n");
    int ans = 0;
    memset(color, 0, sizeof(color[0]) * t);
    for (int i = 0; i < t; i++) {
      if (color[i])
        continue;
      edge_count = vertex_count = 0;
      dfs(i, 0);
      ans += edge_count / 2 - (vertex_count - 1);
    }
    printf("Case #%d: %d\n", test, ans);
    // break;
  }
  return 0;
}

