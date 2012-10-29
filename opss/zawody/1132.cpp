#include <cstdio>

int main() {
    int d, x, y;

    scanf("%d", &d);

    while (d--) {
        scanf("%d %d", &x, &y);
        if ((x & 1) || (y & 1))
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}
