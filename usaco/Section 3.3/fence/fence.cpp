/*
ID: piotrek4
LANG: C++
PROG: fence
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

ifstream fin("fence.in");
ofstream fout("fence.out");
int f;
multiset<int> g[MAX_N];
vector<int> c;
int deg[MAX_N];

void find_cycle(int u) {
    while (!g[u].empty()) {
        int v = *g[u].begin();
        g[u].erase(g[u].begin());
        g[v].erase(g[v].find(u));
        find_cycle(v);
    }
    c.push_back(u);
}

int main() {
    int a, b;
    int start = MAX_N;
    fin >> f;

    for (int i = 0; i < f; ++i) {
        fin >> a >> b;
        start = min(start, min(a, b));
        g[a].insert(b);
        g[b].insert(a);
        ++deg[a];
        ++deg[b];
    }

    int start2 = MAX_N;
    for (int i = 1; i < MAX_N; ++i) {
        if (deg[i] & 1)
            start2 = min(start2, i);
    }

    if (start2 != MAX_N)
        find_cycle(start2);
    else
        find_cycle(start);

    for (int i = c.size()-1; i >= 0; --i)
        fout << c[i] << endl;
    return 0;
}
