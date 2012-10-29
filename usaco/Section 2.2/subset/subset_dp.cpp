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

int n;
long long dp[64][1024];

int main() {
    fin >> n;

    int s = n*(n+1)/2;
    if (s % 2 != 0) {
        fout << 0 << endl;
    } else {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= s; ++j) {
                if (dp[i][j] > 0) {
                    dp[i+1][j+i] += dp[i][j];
                    if (i > 1) dp[i+1][abs(j-i)] += dp[i][j];
                }
            }
        }
        fout << dp[n+1][0] << endl;
    }

    return 0;
}
