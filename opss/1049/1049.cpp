#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_COINS = 105;
const int MAX_N = 1005;
const int MAX = 100005;

int m[MAX_COINS];
int t[MAX_N];

int main() {
    int c, n, k;
    int res;

    scanf("%d", &c);
    while (c--) {
        res = 0;
        scanf("%d %d", &n, &k);
        t[0] = 0;
        for (int i = 1; i <= n; ++i)
            t[i] = MAX;
        for (int i = 0; i < k; ++i)
            scanf("%d", &m[i]);
        for (int i = 0; i < k; ++i) {
            for (int j = m[i]; j <= n; ++j) {
                int prev = t[j - m[i]];
                if (prev >= 0)
                    t[j] = min(t[j], prev + 1);
            }
        }
        if (t[n] == MAX)
            printf("0\n");
        else
            printf("%d\n", t[n]);

    }
    return 0;
}
