#include <cstdio>
#include <cmath>

int calc(int x) {
    int r = (int) sqrt(x);
    int result = 0;

    for (int i = 0; i <= r; ++i) {
        int j = x - i * i;
        int tmp = (int) sqrt(j);
        if (tmp * tmp + i * i == x) {
            ++result;
        }
    }

    return result;
}

int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        printf("%d\n", (calc(x) + 1) / 2);
    }
    return 0;
}
