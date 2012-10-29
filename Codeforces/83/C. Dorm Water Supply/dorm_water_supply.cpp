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

const int INF = 1 << 26;
const int MAX_N = 1005;

int n, p;
int in[MAX_N];
int g[MAX_N];
int d[MAX_N];
int tap = -1;
int sols;
int mind = INF;

void dfs(int v) {
    if (g[v] != 0) {
        mind = min(mind, d[v]);
        dfs(g[v]);
    } else {
        tap = v;
    }
}

int main() {
    int a, b, dia;
    scanf("%d%d", &n, &p);

    memset(d, 0, sizeof(d));

    for (int i = 0; i < p; ++i) {
        scanf("%d%d%d", &a, &b, &dia);
        g[a] = b;
        d[a] = dia;
        in[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0 && g[i] != 0) sols++;
    }

    printf("%d\n", sols);
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0 && g[i] != 0) {
            tap = -1;
            mind = INF;
            dfs(i);
            printf("%d %d %d\n", i, tap, mind);
        }
    }

    return 0;
}
