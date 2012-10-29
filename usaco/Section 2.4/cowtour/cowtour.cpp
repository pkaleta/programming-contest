/*
ID: piotrek4
LANG: C++
PROG: cowtour
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
#include <cmath>
#include <iomanip>

using namespace std;


const int MAX_N = 160;
const int INF = 1 << 28;

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
vector<pair<int, int> > points;
double g[MAX_N][MAX_N];
double farthest[MAX_N];
int n;



void calcDists() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

double getDist(int p1, int p2) {
    int a = abs(points[p1].first - points[p2].first);
    int b = abs(points[p1].second - points[p2].second);
    return sqrt(a*a+b*b);
}

double calcFarthest() {
    double ret = 0.0f;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && g[i][j] < INF) {
                farthest[i] = max(farthest[i], g[i][j]);
            }
        }
    }
    return ret;
}


double getResult() {
    double ret = INF;
    double tmp = 0.0f;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i != j && g[i][j] != INF){
                tmp = max(tmp, g[i][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i != j && g[i][j] == INF) {
                ret = min(ret, farthest[i] + farthest[j] + getDist(i, j));
            }
        }
    }
    return max(ret, tmp);
}


int main() {
    int x, y;
    string line;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        fin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; ++i) {
        fin >> line;
        for (int j = 0; j < n; ++j) {
            if (line[j] == '1') g[i][j] = g[j][i] = getDist(i, j);
            else g[i][j] = g[j][i] = INF;
        }
    }

    calcDists();
    calcFarthest();

    fout << fixed;
    fout << setprecision(6) << getResult() << endl;

    return 0;
}
