#include <stdio.h>

int main() {
    int d, sum, x, n, c;

    scanf("%d\n", &d);
    for (int i = 0; i < d; ++i) {
        sum = 0;
        scanf("%d\n", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d\n", &x);
            sum += x;
        }
        scanf("%d\n", &c);

        printf("%d\n", c % sum);
    }
}
