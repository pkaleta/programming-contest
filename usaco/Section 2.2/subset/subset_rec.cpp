/*
ID: piotrek4
LANG: C++
PROG: subset
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


ifstream fin("subset.in");
ofstream fout("subset.out");

int ret = 0;
int n;
map<vector<int>, int> dp;


long long calc(int a, int b, int i) {
    if (a > 0 && i > a) return 0;
    if (b > 0 && i > b) return 0;
    if (i == n+1) {
        if (a == 0 && b == 0) return 1;
        return 0;
    }

    int vv[3] = {a, b, i};
    vector<int> v(vv, vv+3);
    if (dp.find(v) != dp.end()) return dp[v];

    long long r1 = calc(a-i, b, i+1);
    long long r2 = calc(a, b-i, i+1);
    dp[v] = r1+r2;

    return r1+r2;
}


int main() {
    fin >> n;

    int s = n*(n+1)/2;
    if (s & 1) {
        fout << 0 << endl;
    }
    else {
        fout << calc(s/2, s/2, 1) / 2 << endl;
    }

    return 0;
}
