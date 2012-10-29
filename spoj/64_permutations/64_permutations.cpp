#include <cstdio>
#include <cstring>

const int max_n = 13;
const int max_k = 99;

int dp[max_n][max_k];

int main() {
    int d, n, k;

    for (int i = 1; i < max_n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < max_n; ++i) {
        for (int j = 1; j < max_k; ++j) {
            dp[i][j] = 0;
            for (int k = 0; k <= i-1; ++k) {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }

    scanf("%d", &d);
    while (d--) {
        scanf("%d%d", &n, &k);
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
