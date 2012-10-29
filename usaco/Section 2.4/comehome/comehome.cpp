/*
ID: piotrek4
LANG: C++
PROG: comehome
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

const int MAX_N = 256;
const int INF = 1 << 28;

int g[MAX_N][MAX_N];


ifstream fin("comehome.in");
ofstream fout("comehome.out");


int main() {
    int p, len;
    char a, b;
    fin >> p;
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            g[i][j] = INF;
        }
    }

    for (int i = 0; i < p; ++i) {
        fin >> a >> b >> len;
        g[a][b] = g[b][a] = min(g[a][b], len);
    }

    for (int k = 0; k < MAX_N; ++k) {
        for (int i = 0; i < MAX_N; ++i) {
            for (int j = 0; j < MAX_N; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ret = INF;
    char past;
    for (char c = 'A'; c < 'Z'; ++c) {
        if (g[c]['Z'] < ret) {
            past = c;
            ret = g[c]['Z'];
        }
    }

    fout << past << " " << ret << endl;

    return 0;
}
