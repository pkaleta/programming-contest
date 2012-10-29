#include <stdio.h>

int main() {
    int k, sum = 0, p, tmp = 1;
    scanf("%d", &k);
    for (int i = 0; i <= k; ++i) {
        scanf("%d", &p);
        sum += p * tmp;
        tmp <<= 1;
    }
    printf ("%d\n", sum + 1);
    return 0;
}
