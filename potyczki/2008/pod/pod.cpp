#include <cstdio>
#include <cstring>

const int MAX_N = 25;
const int MOD = 1000000009;

long long tab[MAX_N][MAX_N], result[MAX_N][MAX_N], result2[MAX_N][MAX_N], x[MAX_N][MAX_N], y[MAX_N][MAX_N];
int mask[MAX_N];
int n, m, k, d, a, b, tmp;
int z;

int next(int mask[], int n) {
    int i;
    for (i = 0; (i < n) && mask[i]; ++i)
        mask[i] = 0;

    if (i < n) {
        mask[i] = 1;
        return 1;
    }
    return 0;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &d);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        tab[a][b] = tab[b][a] = 1;
    }
    memset(mask, 0, sizeof(mask));
    tmp = d-1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            result[i][j] = 0;
            y[i][j] = x[i][j] = tab[i][j];
        }
        result[i][i] = 1;
    }

    while (tmp) {

        if (tmp % 2) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    y[i][j] = result[i][j];

            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) {
                    result[i][j] = 0;
                    for (int k = 1; k <= n; ++k)
                        result[i][j] = (result[i][j] + (y[i][k] * x[k][j])%MOD) % MOD;
                }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                y[i][j] = x[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                x[i][j] = 0;
                for (int k = 1; k <= n; ++k)
                    x[i][j] = (x[i][j] + (y[i][k] * y[k][j])%MOD) % MOD;
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                y[i][j] = x[i][j];

        tmp /= 2;
    }
/*
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%d ", result[i][j]);
            printf("\n");
        }
        printf("******************\n");*/
    int range = min(k, 7);
    while (next(mask, range)) {
//        printf("########## podzbior:\n");
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                y[i][j] = tab[i][j];

        int count = 0;
        for (int i = 0; i < n; ++i)
            if (mask[i]) {
  //              printf("%d ", i + 1);
                ++count;
                for (int j = 1; j <= n; ++j)
                    y[i + 1][j] = y[j][i + 1] = 0;
            }
//        printf("\n");

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                x[i][j] = y[i][j];
                result2[i][j] = 0;
            }
            result2[i][i] = 1;
        }

        tmp = d-1;
        while (tmp) {

            if (tmp % 2) {
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= n; ++j)
                        y[i][j] = result2[i][j];

                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= n; ++j) {
                        result2[i][j] = 0;
                        for (int k = 1; k <= n; ++k)
                            result2[i][j] = ( result2[i][j] + (y[i][k] * x[k][j])%MOD) % MOD;
                    }
            }
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    y[i][j] = x[i][j];
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) {
                    x[i][j] = 0;
                    for (int k = 1; k <= n; ++k)
                        x[i][j] = (x[i][j] + (y[i][k] * y[k][j])%MOD) % MOD;
                }
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    y[i][j] = x[i][j];

            tmp /= 2;
        }
        
/*        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%d ", result2[i][j]);
            printf("\n");
        }
        printf("******************\n");*/
 
        tmp = 1;
        if (count % 2)
            tmp *= -1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                result[i][j] = (result[i][j] + tmp * result2[i][j]) % MOD;
    }
/*        printf("******************\n");
        printf("******************\n");
        printf("******************\n");
        printf("******************\n");
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%d ", result[i][j]);
            printf("\n");
        }
        printf("******************\n");*/
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            sum = (sum + result[i][j]) % MOD;
    printf("%lld\n", sum);
    return 0;
}
