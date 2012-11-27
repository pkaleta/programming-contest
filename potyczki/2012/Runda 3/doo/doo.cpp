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


const int MAX_N = 100005;
const int MAX_M = 200005;
const bool WEST = true;
const bool EAST = false;
const int MAX_DIST = 1029600;
const long long INF = 1LL << 60LL;


struct Edge {
  int dest;
  long long cost;
  long long dist;

  Edge(int _dest, long long _cost, long long _dist) : dest(_dest), cost(_cost), dist(_dist) {}
};


int main() {
  int n, m;
  int w[MAX_N];
  int a, b, k;
  int x;
  int distance;
  vector<Edge*> edges[MAX_N];

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &w[i]);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d%d", &a, &b, &x, &k);
    if (k == 1) {
      if (w[b] > w[a])
        distance = w[b] - w[a];
      else
        distance = MAX_DIST - (w[a] - w[b]);
    }
    else {
      if (w[a] > w[b])
        distance = w[a] - w[b];
      else
        distance = MAX_DIST - (w[b] - w[a]);
      distance = -distance;
    }

    edges[a].push_back(new Edge(b, x, distance));
    edges[b].push_back(new Edge(a, x, -distance));
  }

  set<pair<long long, int> > pq;

  long long dist[MAX_N];
  long long cost[MAX_N];
  cost[1] = 0;
  for (int i = 2; i <= n; ++i) {
    dist[i] = 0LL;
    cost[i] = INF;
  }

  pq.insert(make_pair(0LL, 1));
  while (!pq.empty()) {
    pair<long long, int> top = *pq.begin();
    pq.erase(pq.begin());

    long long cur_cost = top.first;
    int v = top.second;

    for (int i = 0; i < edges[v].size(); ++i) {
      Edge* edge = edges[v][i];
      if (cur_cost + edge->cost < cost[edge->dest]) {
        if (cost[edge->dest] != INF)
          pq.erase(pq.find(make_pair(cost[edge->dest], edge->dest)));

        cost[edge->dest] = cur_cost + edge->cost;
        dist[edge->dest] = dist[v] + edge->dist;
        pq.insert(make_pair(cost[edge->dest], edge->dest));
      }
    }
  }

  long long min_cost = INF;

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < edges[i].size(); ++j) {
      Edge* edge = edges[i][j];
      if (dist[i] + edge->dist - dist[edge->dest] != 0LL) {
        // cout << i << "->" << edge->dest << "*******" << cost[i] << "," << edge->cost << "," << cost[edge->dest] << "*****" << " " << dist[i] << "," << edge->dist << "," << dist[edge->dest] << endl;
        min_cost = min(min_cost, cost[i] + edge->cost + cost[edge->dest]);
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << i << ": " << cost[i] << " " << dist[i] << endl;
  // }

  if (min_cost == INF)
    printf("-1\n");
  else
    printf("%lld\n", min_cost);
  return 0;
}
