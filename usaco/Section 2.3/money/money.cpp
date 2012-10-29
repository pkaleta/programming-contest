/*
ID: piotrek4
LANG: C++
PROG: money
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


ifstream fin("money.in");
ofstream fout("money.out");

const int MAX_N = 10005;
long long unsigned dp[MAX_N];

int main() {
    int v, n, c;

    fin >> v >> n;

    dp[0] = 1;
    for (int i = 0; i < v; ++i) {
        fin >> c;
        for (int j = c; j <= n; ++j) dp[j] += dp[j-c];
    }

    fout << dp[n] << endl;

    return 0;
}
