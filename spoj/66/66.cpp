#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2005;

int lcs(int* a, int al, int* t, int tl)
{
    int dp[MAXN];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= al; ++i)
    {
        int prev = dp[0];
        for (int j = 1; j <= tl; ++j)
        {
            int tmp = dp[j];
            dp[j] = max(dp[j-1], dp[j]);
            if (a[i] == t[j])
                dp[j] = max(dp[j], 1+prev);
            prev = tmp;
        }
    }

    return dp[tl]-1;
}

void read(int* t, int& n)
{
    n = 0;
    while(1)
    {
        scanf("%d", &t[n]);
        if (!t[n++])
            break;
    }
}

int main()
{
    int d;
    int a[MAXN];
    int t[MAXN];

    scanf("%d", &d);
    for (int c = 0; c < d; ++c)
    {
        int ret = 0;
        int al, tl;

        memset(a, 0, sizeof(MAXN));

        read(a+1, al);
        while(1)
        {
            memset(t, 0, sizeof(MAXN));
            read(t+1, tl);

            if (!t[1])
                break;

            ret = max(ret, lcs(a, al, t, tl));
        }
        printf("%d\n", ret);
    }
    return 0;
}
