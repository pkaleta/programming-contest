#include <cstdio>
#include <cmath>

int main() {
    int d;
    double k, s, a, r;

    scanf("%d", &d);
    while (d--) {
        scanf("%lf %lf", &a, &r);
        s = a * a * a;
        k = (4.0 / 3.0) * M_PI * r * r * r;
        if (k > s)
            printf("K\n");
        else if (s > k)
            printf("S\n");
        else
            printf("R\n");
    }
    return 0;
}
