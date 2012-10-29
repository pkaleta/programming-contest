#include <iostream>
#include <queue>
#include <vector>
#include <set>


using namespace std;

const long long MAX_N = 1005;
const long long INF = 1LL << 60LL;

long long n, m, x, y;
vector<long long> e[MAX_N];
vector<long long> f[MAX_N];
vector<long long> g[MAX_N];

long long dist[MAX_N];
set<pair<long long, long long> > q;

void dijkstra(long long u) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[u] = 0;
    q.insert(make_pair(0, u));

    while (!q.empty()) {
        u = q.begin()->second;
        q.erase(q.begin());

        for (int i = 0; i < e[u].size(); ++i) {
            long long v = e[u][i];
            long long d = f[u][i];

            if (dist[v] > dist[u]+d) {
                dist[v] = dist[u]+d;
                q.insert(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    long long u, v, w, t, c[MAX_N];
    cin >> n >> m >> x >> y;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        e[u].push_back(v);
        f[u].push_back(w);
        e[v].push_back(u);
        f[v].push_back(w);
    }
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
        cin >> t >> c[i];

        for (int j = 1; j <= n; ++j) {
            if (i != j && dist[j] <= t) {
                g[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        f[i].clear();
        for (int j = 0; j < g[i].size(); ++j) {
            e[i].push_back(g[i][j]);
            f[i].push_back(c[i]);
        }
    }

    dijkstra(x);

    if (dist[y] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[y] << endl;
    }

    return 0;
}
