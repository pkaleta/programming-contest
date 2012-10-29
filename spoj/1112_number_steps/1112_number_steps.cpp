#include <cstdio>

int main() {
    int tc;
    int x, y;

    scanf("%d", &tc);

    while(tc--) {
        scanf("%d%d", &x, &y);
        if (y == x || (y == x-2 && x-2 >= 0)) {
            if (x & 1 || y & 1) {
                printf("%d\n", x+y-1);
            } else {
                printf("%d\n", x+y);
            }
        } else {
            printf("No Number\n");
        }
    }
    return 0;
}
