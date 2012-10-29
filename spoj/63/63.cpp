#include <cstdio>
#include <cstring>

int MAXN = 42;

long long calc(int n, int k, int* s)
{
    long long dp[MAXN][MAXN];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 0; i < 2*n; ++i)
        for (int j = 0; j <= 2*n; ++j)
        {
            dp[j+1][i+1] += dp[j][i];

            if (!s[i+1])
                dp[j-1][i+1] += dp[j][i];
        }

    return dp[0][2*n];
}

int main()
{
    int d;
    int n, k;
    int s[MAXN];

    for (scanf("%d", &d); d--;)
    {
        memset(s, 0, sizeof(s));
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            s[tmp] = 1;
        }

        printf("%lld\n", calc(n, k, s));
    }
    return 0;
}
