#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 2005;

long long memo[MAX][MAX];
long long t[MAX];

long long f(long long t[], int l, int r) {
    if (l == r)
        return 0;
    if (l + 1 == r)
        return t[l];
    if (l + 2 == r)
        return t[l] + t[l + 1];

    long long m = -1;
    for (int i = l; i < r; ++i) {
        long long a;
        long long b;
        if (memo[l][i])
            a = memo[l][i];
        else {
            a = f(t, l, i);
            memo[l][i] = a;
        }
        if (memo[i + 1][r])
            b = memo[i + 1][r];
        else {
            b = f(t, i + 1, r);
            memo[i + 1][r] = b;
        }
        int tmp = t[i] + max(a, b);
        if (m == -1 || tmp < m)
            m = tmp;
    }
    return m;
}

int main() {

    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &t[i]);

    printf("%lld\n", f(t, 0, n));

    return 0;
}
