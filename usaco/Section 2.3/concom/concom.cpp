/*
ID: piotrek4
LANG: C++
PROG: concom
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


ifstream fin("concom.in");
ofstream fout("concom.out");


const int MAX_N = 105;
int p[MAX_N][MAX_N];
int pp[MAX_N][MAX_N];
bool visited[MAX_N];


void dfs(int s, int v) {
    visited[v] = true;
    for (int i = 0; i < MAX_N; ++i) {
        if (!visited[i]) {
            pp[s][i] += pp[v][i];
            if (pp[s][i] > 50) {
                dfs(s, i);
            }
        }
    }
}


int main() {
    int n, a, b;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a >> b;
        fin >> p[a-1][b-1];
    }

    for (int i = 0; i < MAX_N; ++i) {
        memcpy(pp, p, sizeof(p));
        memset(visited, 0, sizeof(visited));
        visited[i] = true;

        for (int j = 0; j < MAX_N; ++j) {
            if (!visited[j] && pp[i][j] > 50) dfs(i, j);
        }

        for (int j = 0; j < MAX_N; ++j) {
            if (i != j && pp[i][j] > 50 && visited[j]) fout << i+1 << " " << j+1 << endl;
        }
    }

    return 0;
}
