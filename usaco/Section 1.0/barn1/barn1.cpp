/*
ID: piotrek4
LANG: C++
PROG: barn1
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

ifstream fin("barn1.in");
ofstream fout("barn1.out");


const int MAX_S = 205;


bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}


int main() {
    int m, c, s;
    int a[MAX_S];
    vector<pair<int, int> > p;

    fin >> m >> s >> c;

    for (int i = 0; i < c; ++i) {
        fin >> a[i];
    }
    sort(a, a+c);

    for (int i = 1; i < c; ++i) {
        if (a[i-1]+1 < a[i]) {
            p.push_back(make_pair(a[i-1]+1, a[i]-a[i-1]-1));
        }
    }

    sort(p.begin(), p.end(), cmp);

    int ret = a[c-1]-a[0]+1;
    for (int i = 0; i < min(m-1, (int)p.size()); ++i) {
        ret -= p[i].second;
    }
    fout << ret << endl;

    return 0;
}
