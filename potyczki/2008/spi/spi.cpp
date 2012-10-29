#include <cstdio>

int main() {
    int n, dbl = 0, sgl = 0;
    char a, b, x;
    scanf("%d\n%c", &n, &a);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%c%c", &x, &b);
        if (a == 'A')
            if (b == 'B' || b == 'D')
                ++dbl;
            else
                ++sgl;
        else if (a == 'C')
            if (b == 'B' || b == 'D')
                ++dbl;
            else
                ++sgl;
        else
            ++sgl;
        a = b;
    }
    if (dbl > sgl)
        printf("%d\n", 2 * dbl);
    else
        printf("%d\n", 2 * dbl + (sgl - dbl));
    return 0;
}
