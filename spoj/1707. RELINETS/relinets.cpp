#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_N = 25;
const int MAX_M = 25;

struct Edge {
  int u;
  int v;
  int cost;

  Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
};

vector<Edge*> edges;


void make_set() {}


int solve(int n, int m) {
  int mc = m;
  int poss_num = 1 << m;

  for (int i = 0; i < poss_num; ++i) {
    int k = i;
    for (int j = 0; j < edges.size(); ++j) {

      k /= 2;
    }
  }
}


int main() {
  int n, m;

  while (2 == scanf("%d%d", &n, &m) && n != 0 || m == 0) {
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      Edge* edge = new Edge(a, b, c);

      int result = solve(n, m);
      printf();
    }
  }
  return 0;
}
