#include <cstdio>
#include <cstdlib>
#include <cmath>

int count_twos(int n) {
    int r = (int) log2(n);
    int res = 0;
    for (int i = 1; i <= r; ++i)
        res += (int) (n / pow(2, i));
    return res;
}


int main() {
    int d;
    int n, k;
    int p, q, r;

    scanf("%d", &d);
    while (d--) {
        scanf("%d %d", &n, &k);
        if (k > n || count_twos(n) > count_twos(k) + count_twos(n - k))
            printf("P\n");
        else
            printf("N\n");
    }
    return 0;
}
