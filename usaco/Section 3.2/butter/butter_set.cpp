/*
ID: piotrek4
LANG: C++
PROG: butter
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>

using namespace std;


const int MAX_N = 505;
const int MAX_P = 805;

ifstream fin("butter.in");
ofstream fout("butter.out");
int n, p, c;
int cnt[MAX_P];
vector<pair<int, int> > g[MAX_P];
long long dist[MAX_P];
const long long INF = 1LL << 26LL;

void dijkstra(int s) {
//    cout << "***************** " << s << endl;
//    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    set<pair<int, int> > q;

    for (int i = 1; i <= p; ++i)
        dist[i] = INF;
    dist[s] = 0;
    q.insert(make_pair(0, s));

    while (!q.empty()) {
        pair<int, int> p = *q.begin();
//        cout << v << " " << dist[v] << endl;
        q.erase(q.begin());
        int d = p.first;
        int v = p.second;

        if (d <= dist[v]) {
            for (int i = 0; i < g[v].size(); ++i) {
                pair<int, int> pp = g[v][i];
                int u = pp.first;
                long long cost = pp.second;
                if (dist[u] > dist[v] + cost) {
                    dist[u] = dist[v] + cost;
                    q.insert(make_pair(dist[u], u));
                }
            }
        }
    }
}


int main() {
    int a, b, l;

    fin >> n >> p >> c;

    for (int i = 0; i < n; ++i) {
        fin >> a;
        ++cnt[a];
    }

    for (int i = 0; i < c; ++i) {
        fin >> a >> b >> l;
        g[a].push_back(make_pair(b, l));
        g[b].push_back(make_pair(a, l));
    }

    long long minDist = 1 << 26;
    for (int i = 1; i <= p; ++i) {
        long long curDist = 0;
        dijkstra(i);
        for (int j = 1; j <= p; ++j)
            curDist += (long long)cnt[j] * dist[j];
        minDist = min(minDist, curDist);
    }

    fout << minDist << endl;

    return 0;
}
