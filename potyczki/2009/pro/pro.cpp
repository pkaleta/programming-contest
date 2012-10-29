#include <cstdio>
#include <cmath>

int main() {
    int n;
    int r = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int a = (int) sqrt(i);
        for (int j = 1; j <= a; ++j)
            if (i % j == 0)
                ++r;
    }

    printf("%d\n", r);

    return 0;
}
