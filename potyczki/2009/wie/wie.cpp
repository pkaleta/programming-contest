#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 2005;

long long m[MAX][MAX];
long long t[MAX];

int main() {

    int n;

    memset(m, 0, sizeof(long long) * MAX * MAX);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &t[i]);

    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < n - l + 1; ++i) {
            int j = i + l - 1;
            if (l == 1)
                m[i][j] = t[i];
            else if (l == 2)
                m[i][j] = t[i] + t[j];
            else {
                m[i][j] = -1;

                for (int k = i + 1; k < j; ++k) {
                    long long q = t[k] + max(m[i][k - 1], m[k + 1][j]);
                    if (m[i][j] == -1 || q < m[i][j])
                        m[i][j] = q;
                }
            }
        }
    }

    printf("%lld\n", m[0][n - 1]);

    return 0;
}
