#include <cstdio>

const int MAX_N = 305;
const long long INFINITY = 30000000005LL;

long long w[MAX_N][MAX_N];

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            w[i][j] = -INFINITY;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        w[a][b] = (long long) c;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (w[i][k] != -INFINITY && w[k][j] != -INFINITY && i != k && k != j)
                    w[i][j] = max(w[i][j], w[i][k] + w[k][j]);
    int count = 0;
    for (int i = 1; i <= n; ++i)
        if (w[i][i] > 0)
            ++count;
    printf("%d\n", count);
    for (int i = 1; i <= n; ++i)
        if (w[i][i] > 0)
            printf("%d ", i);
    printf("\n");
    return 0;
}
