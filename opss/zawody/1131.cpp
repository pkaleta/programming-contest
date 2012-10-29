#include <cstdio>

int main() {
    int d;
    int m, n, x, y;

    scanf("%d", &d);
    while (d--) {
        scanf("%d %d %d %d", &m, &n, &x, &y);
        if ((x & 1) && (y & 1))
            printf("NIE\n");
        else
            printf("TAK\n");
    }
    return 0;
}
