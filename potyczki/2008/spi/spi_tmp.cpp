#include <cstdio>
#include <cstring>

const int MAX_N = 5000005;

int main() {
    int n, sum = 0;
    char tab[MAX_N];
    memset(tab, 0, sizeof(tab));
    char a, b, x;
    scanf("%d\n%c", &n, &a);
    for (int i = 0; i < n-1; ++i) {
        scanf("%c%c", &x, &b);
        if (a == 'A')
            if (b == 'B' || b == 'D')
                tab[i] = 2;
            else
                tab[i] = 1;
        else if (a == 'C')
            if (b == 'B' || b == 'D')
                tab[i] = 2;
            else 
                tab[i] = 1;
        else
            tab[i] = 1;
        a = b;
    }
    for (int i = 0; i < n-2; ++i) {
        if (tab[i] == 2) {
            sum += 2;
            --tab[i + 1];
        }
        else if (tab[i] == 1) {
            if (tab[i + 1] == 2) {
                tab[i + 1] = tab[i] = 0;
                sum += 2;
            }
            else
                sum += 1;
        }
    }
    sum += tab[n - 2];
    printf("%d\n", sum);
    return 0;
}
