#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>


const int MAX_N = 25;
const int MAX_M = 25;

struct Edge {
  int u;
  int v;
  int cost;

  Edge(int _u, int _v, int _c) : u(_u), v(_v), cost(_c) {}
};

typedef std::vector<Edge*> Edges;


class UnionFind {
 private:
  int *parent;
  int *set_rank;
  int set_count;

  void make_set(int x) {
    parent[x] = x;
    set_rank[x] = 0;
  }

 public:
  UnionFind(int n) {
    parent = new int[n];
    set_rank = new int[n];

    for (int i = 0; i < n; ++i)
      make_set(i);
    set_count = n;
  }

  ~UnionFind() {
    delete[] parent;
    delete[] set_rank;
  }

  int is_single_component() {
    return set_count == 1;
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);

    if (x_root == y_root)
      return;

    if (set_rank[x_root] < set_rank[y_root])
      parent[x_root] = y_root;
    else if (set_rank[x_root] > set_rank[y_root])
      parent[y_root] = x_root;
    else {
      parent[y_root] = x_root;
      set_rank[x_root] = set_rank[x_root] + 1;
    }
    set_count -= 1;
  }
};


int solve(int n, int m, Edges& edges) {
  int min_cost = std::numeric_limits<int>::max();
  int mc = m;
  int poss_num = 1 << m;
  int deg[MAX_N];

  for (int i = 0; i < poss_num; ++i) {
    int k = i;
    int current_cost = 0;
    memset(deg, 0, sizeof(deg));
    UnionFind uf = UnionFind(n);

    for (int j = 0; j < m; ++j) {
      if (k & 1) {
        uf.merge(edges[j]->u, edges[j]->v);
        ++deg[edges[j]->u];
        ++deg[edges[j]->v];
        current_cost += edges[j]->cost;
      }
      k >>= 1;
    }

    bool biconnected = true;
    for (int j = 0; j < n; ++j)
      if (deg[j] < 2 || (deg[j] & 1))
        biconnected = false;

    if (uf.is_single_component() && biconnected)
      min_cost = std::min(min_cost, current_cost);
  }
  return min_cost;
}


int main() {
  int n, m;
  int u, v, c;
  int tc = 1;
  Edges edges;

  while (2 == scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
    edges.clear();

    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &u, &v, &c);
      Edge* edge = new Edge(u - 1, v - 1, c);
      edges.push_back(edge);
    }

    int result = solve(n, m, edges);

    if (result == std::numeric_limits<int>::max())
      printf("There is no reliable net possible for test case %d.\n", tc++);
    else
      printf("The minimal cost for test case %d is %d.\n", tc++, result);
  }
  return 0;
}
