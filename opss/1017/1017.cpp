#include <cstdio>

int main() {
    int n;
    int a, b;

    scanf("%d", &n);
    int nines = 0;
    int last = -1;
    bool needNewLast = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        int s = a + b;
        if (s < 9) {
            if (needNewLast) {
                last = s;
                needNewLast = false;
            } else {
                printf("%d", last);
                for (int j = 0; j < nines; ++j)
                    printf("9");
                nines = 0;
                last = s;
            }
        } else if (s == 9) {
            ++nines;
        }
        else {
            if (needNewLast) {
                last = s;
                needNewLast = false;
            } else {
                printf("%d", last + 1);
                for (int j = 0; j < nines; ++j)
                    printf("0");
                nines = 0;
                last = s % 10;
            }
        }
    }
    if (last != -1)
        printf("%d", last);
    for (int j = 0; j < nines; ++j)
        printf("9");
    printf("\n");

    return 0;
}

