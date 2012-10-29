/*
ID: piotrek4
LANG: C++
PROG: agrinet
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 105;
const int INF = 1 << 26;


ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

int n;
int g[MAX_N][MAX_N];
int dist[MAX_N];
bool intree[MAX_N];


int getMin() {
    int ret = -1;
    int minDist = INF;
    for (int i = 0; i < n; ++i) {
        if (!intree[i] && minDist > dist[i]) {
            minDist = dist[i];
            ret = i;
        }
    }
    return ret;
}


int mst() {
    int count = 0;
    int ret = 0;

    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[0] = 0;

    while (count < n) {
        int v = getMin();
//        cout << "*********** " << v << " " << dist[v] << endl;
        ret += dist[v];
        intree[v] = true;
        ++count;

        for (int i = 0; i < n; ++i) {
            if (!intree[i]) dist[i] = min(dist[i], g[v][i]);
        }
    }

    return ret;
}

int main() {

    fin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> g[i][j];
        }
    }

    fout << mst() << endl;

    return 0;
}
