#include <cstdio>
#include <cstring>

const int MAX_N = 50005;

int a[MAX_N];
int b[MAX_N];

int main() {
    int d;
    int n, k;

    scanf("%d", &d);
    while (d--) {
        memset(b, 0, sizeof(int) * MAX_N);
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < k; ++i) {
            int tmp;
            scanf("%d", &tmp);
            ++b[tmp];
        }
        if (!b[a[n - 1]])
            printf("NIE\n");
        else {
            for (int i = n - 1; i >= 0; --i) {
                if (b[a[i]])
                    --b[a[i]];
            }
            int s = 0;
            for (int i = 0; i < MAX_N; ++i)
                s += b[i];
            if (s > 0)
                printf("NIE\n");
            else
                printf("TAK\n");
        }
    }
    return 0;
}
