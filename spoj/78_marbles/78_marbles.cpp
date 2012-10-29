#include <cstdio>

long long f(long long n, long long k) {
    long double res = 1;
    if (k > n)
        return 0;
    if (k > n-k)
        k = n-k;
    for (int i = 1; i <= k; ++i) {
        res *= n--;
        res /= i;
    }
    return (long long)res;
}

int main() {
    int t, n, k;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        printf("%lld\n", f(n-1, k-1));
    }
    return 0;
}
