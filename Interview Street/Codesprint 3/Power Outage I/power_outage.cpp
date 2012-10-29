#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

const int MAX_V = 2005;

struct Edge {
  int u;
  int v;
  int c;

  Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
};

int T;
vector<Edge*> edges;
int parent[MAX_V];
int set_rank[MAX_V];
int set_count;


bool cmp_edges(const Edge* e1, const Edge* e2)
{
  return e1->c < e2->c;
}


void make_set(int x) {
  parent[x] = x;
  set_rank[x] = 0;
}


int find(int x) {
  if (parent[x] != x)
    parent[x] = find(parent[x]);
  return parent[x];
}


void merge(int x, int y) {
  int x_root = find(x);
  int y_root = find(y);
  set<int>::iterator it;

  if (x_root == y_root)
    return;

  // x and y are not already in same set. Merge them.
  if (set_rank[x_root] < set_rank[y_root]) {
    parent[x_root] = y_root;
  }
  else if (set_rank[x_root] > set_rank[y_root]) {
    parent[y_root] = x_root;
  }
  else {
    parent[y_root] = x_root;
    set_rank[x_root] = set_rank[x_root] + 1;
  }
  set_count -= 1;
}


void initialize(int n) {
  for (int i = 1; i <= n; ++i) {
    make_set(i);
  }
  set_count = n;
}


int calc_mst(int n, int m, int k) {
  if (n <= k) return 0;
  if (m == 0) return -1;

  sort(edges.begin(), edges.end(), cmp_edges);

  int mst_cost = 0;

  for (vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it) {
    Edge* edge = *it;
    int u = edge->u;
    int v = edge->v;
    int u_tree = find(u);
    int v_tree = find(v);
    if (u_tree != v_tree) {
      mst_cost += edge->c;
      merge(u_tree, v_tree);
    }
    if (set_count == k)
      return mst_cost;
  }
  return -1;
}


int main() {
  int n, m, k;
  int u, v, c;

  scanf("%d", &T);

  while (T--) {
    scanf("%d%d%d", &n, &m, &k);

    initialize(n);

    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &u, &v, &c);
      Edge* edge = new Edge(u, v, c);
      edges.push_back(edge);
    }

    int result = calc_mst(n, m, k);

    if (result == -1)
      printf("Impossible!\n");
    else
      printf("%d\n", result);
  }

  return 0;
}
