#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>

using namespace std;


const int MAX_N = 1005;

int n, m, c0, d0;
int ret = 0;
int dp[MAX_N];

void add(int dough, int price) {
    for (int i = n; i >= dough; --i)
        dp[i] = max(dp[i], dp[i-dough]+price);
}

int main() {
    int a, b, c, d;

    scanf("%d%d%d%d", &n, &m, &c0, &d0);
    for (int i = 0; i < n/c0; ++i) add(c0, d0);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        for (int i = 0; i < a/b; ++i) add(c, d);
    }
    printf("%d\n", *max_element(dp, dp+n+1));

    return 0;
}
