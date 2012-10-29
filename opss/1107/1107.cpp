#include <cstdio>

const int MAX_N = 55;

int t[MAX_N][2];

int main() {
    int n, m, k, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &t[i][0], &t[i][1]);

    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        scanf("%d", &m);
        int min = -1;
        int max = 50;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a);
            if (t[a][0] > min)
                min = t[a][0];
            if (t[a][1] < max)
                max = t[a][1];
        }
        if (min <= max)
            printf("%d %d\n", min, max);
        else
            printf("NIE\n");
    }
    return 0;
}
