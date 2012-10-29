/*
ID: piotrek4
LANG: C++
PROG: inflate
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

const int MAX_N = 10005;
const int MAX_M = 10005;
const int INF = 1 << 26;


ifstream fin("inflate.in");
ofstream fout("inflate.out");

int m, n;
int t[MAX_N];
int p[MAX_N];
int dp[MAX_M];

int main() {
    fin >> m >> n;
    int ret;

    for (int i = 0; i < n; ++i) {
        fin >> p[i] >> t[i];
        dp[t[i]] = max(dp[t[i]], p[i]);
        ret = max(ret, dp[t[i]]);
        for (int j = t[i]; j <= m; ++j) {
            if (j-t[i] > 0) {
                dp[j] = max(dp[j], dp[j-t[i]]+p[i]);
                ret = max(ret, dp[j]);
            }
        }
    }

    fout << ret << endl;

    return 0;
}
