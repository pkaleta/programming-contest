#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;
    long long a, b, c;

    scanf("%d", &n);
    while (n--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        a *= 1760 * 3 * 12;
        b *= 1760 * 3 * 12;
        c *= 1760 * 3 * 12;

        double M = tan((c * M_PI_2) / a);
        double N = 1 / (2 * M);
        long long x = (long long) round((2 * a / M_PI) * asin(sqrt(N * N + 1) - N));
        long long m, j, s, c;
        m = x / (1760 * 3 * 12);
        x %= (1760 * 3 * 12);
        j = x / (3 * 12);
        x %= (3 * 12);
        s = x / 12;
        c = x % 12;
        printf("%lld %lld %lld %lld\n", m, j, s, c);
    }
    return 0;
}
