#include <cstdio>
#include <cmath>

int main() {
    int d, a, r;
    double k, s;

    scanf("%d", &d);
    while (d--) {
        scanf("%d %d", &a, &r);
        s = (double) a * a * a;
        k = (4.0 / 3.0) * M_PI * (double) (r * r * r);
        if (k > s)
            printf("K\n");
        else if (s > k)
            printf("S\n");
        else
            printf("R\n");
    }
    return 0;
}
