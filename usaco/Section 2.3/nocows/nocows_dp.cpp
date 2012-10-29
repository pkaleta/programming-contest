/*
ID: piotrek4
LANG: C++
PROG: nocows
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


ifstream fin("nocows.in");
ofstream fout("nocows.out");

const int MOD = 9901;

int dp[205][105];
int small[205][105];

int main() {
    int N, K, c;
    fin >> N >> K;

    dp[1][1] = 1;

    for (int k = 1; k <= K; ++k) {
        for (int n = 1; n <= N; ++n) {
            for (int nleft = 1; nleft <= n-1-nleft; nleft += 2) {
                int nright = n-1-nleft;
                c = nleft != nright ? 2 : 1;
                dp[n][k] += c*(
                        dp[nleft][k-1]*small[nright][k-2]+
                        small[nleft][k-2]*dp[nright][k-1]+
                        dp[nleft][k-1]*dp[nright][k-1]);
                dp[n][k] %= MOD;
            }
        }
        for (int n = 0; n <= N; ++n) {
            small[n][k] += dp[n][k]+small[n][k-1];
            small[n][k] %= MOD;
        }
    }

    fout << dp[N][K] << endl;
    return 0;
}
