#include <cstdio>

const int MAX_N = 100;

int t[MAX_N];

int main() {
    int c, n;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        long long s = 0;
        long long min;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t[i]);
            s += t[i];
        }
        min = s;
        for (int i = 0; i < n; ++i) {
            long long tmp = s - t[i];
            if (tmp < min)
                min = tmp;
        }
        printf("%lld\n", min);
    }
    return 0;
}
