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

int solve(int n, int k) {
//    cout << n << ", " << k << endl;
    if (k > n) return 0;
    if (n < 0 || k < 0) return 0;
    if (n > 0 && k == 0) return 0;
    if (n == 0 && k > 0) return 0;
    if (n == 0) return 0;
    if (n == 1 && k == 1) return 1;

    if (dp[n][k] != -1) return dp[n][k];

    int ret = 0;
    int left = 0;
    int right = 0;
    for (int nleft = 2*k-3; nleft < n-1; ++nleft) {
        left = solve(nleft, k-1);
        for (int kright = 0; kright < k-1; ++kright) {
            right = solve(n-1-nleft, kright);
            ret = (ret+left*right)%MOD;
        }
    }
    for (int nright = 2*k-3; nright < n-1; ++nright) {
        left = solve(nright, k-1);
        for (int kleft = 0; kleft < k-1; ++kleft) {
            right = solve(n-1-nright, kleft);
            ret = (ret+left*right)%MOD;
        }
    }
    for (int nleft = 2*k-3; nleft < n-1; ++nleft) {
        left = solve(nleft, k-1);
        right = solve(n-1-nleft, k-1);
        ret = (ret+left*right)%MOD;
    }

//    cout << n << ", " << k << " = " << 2*ret << endl;

    dp[n][k] = ret;
    return ret;
}


int main() {
    int n, k;

    fin >> n >> k;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = -1;
        }
    }
    fout << solve(n, k) << endl;
    return 0;
}
