/*
ID: piotrek4
LANG: C++
PROG: frac1
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


ifstream fin("frac1.in");
ofstream fout("frac1.out");


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    int n1 = a.first;
    int d1 = a.second;
    int n2 = b.first;
    int d2 = b.second;

    if (n1 == 0) return true;

    if (d1 == d2) return n1 < n2;

    int l = lcm(d1, d2);
    return n1*(l/d1) < n2*(l/d2);
}

int main() {
    int m;
    map<pair<int, int>, bool> fs;
    vector<pair<int, int> > ret;
    map<pair<int, int>, bool>::iterator it;

    fin >> m;

    fs[make_pair(0, 1)] = true;
    for (int n = 1; n <= m; ++n) {
        for (int d = n; d <= m; ++d) {
            int g = gcd(n,d);
            int nn = n/g;
            int dd = d/g;

            fs[make_pair(nn, dd)] = true;
        }
    }

    for (it = fs.begin(); it != fs.end(); ++it) {
        ret.push_back(it->first);
    }

    sort(ret.begin(), ret.end(), cmp);

    for (int i = 0; i < ret.size(); ++i) {
        fout << ret[i].first << "/" << ret[i].second << endl;
    }

    return 0;
}
