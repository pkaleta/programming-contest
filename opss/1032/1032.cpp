#include <cstdio>

const int MAX_N = 55;
long long t[MAX_N][MAX_N];

int main() {
    int c;
    char s[MAX_N];
    int n;

    scanf("%d\n", &c);
    while (c--) {
        scanf("%s", &s);
        n = 0;
        while(s[n]) {
            t[n][n] = 1;
            ++n;
        };
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i + j < n; ++i) {
                t[i][i + j] = t[i][i + j - 1] + t[i + 1][i + j];

                if (j > 1)
                    t[i][i + j] -= t[i + 1][i + j - 1];

                if (s[i] == s[i + j]) {
                    if (j > 1)
                        t[i][i + j] += t[i + 1][i + j - 1] + 1;
                    else
                        ++t[i][i + j];
                }
            }
        }
        printf("%lld\n", t[0][n - 1]);
    }
    return 0;
}
