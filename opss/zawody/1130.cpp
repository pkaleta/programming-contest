#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
const int MAX_K = 1005;

int t[MAX_K];

int main() {
    int d;
    int k, n;

    scanf("%d", &d);

    while (d--) {
        scanf("%d %d", &k, &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &t[i]);
        sort(t, t + n);
        int res = 0;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (i == j || t[i] + t[j] <= k) {
                ++i;
                --j;
                ++res;
            }
            else {
                --j;
                ++res;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
