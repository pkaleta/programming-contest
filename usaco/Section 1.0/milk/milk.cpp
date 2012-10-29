/*
ID: piotrek4
LANG: C++
PROG: milk
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");

const int MAX_M = 5005;
vector<pair<int, int> > f;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n, m, p, a;
    int ret = 0;
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        fin >> p >> a;
        f.push_back(make_pair(p, a));
    }

    sort(f.begin(), f.end(), cmp);

    int i = 0;
    while (n > 0) {
        p = f[i].first;
        a = f[i].second;

        int g = min(n, a);
        n -= g;
        ret += g*p;
        ++i;
    }
    fout << ret << endl;

    return 0;
}
