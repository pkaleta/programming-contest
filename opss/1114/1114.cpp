#include <cstdio>

using namespace std;

int main() {
    long long l, n, b;

    scanf("%lld", &l);
    while (l--) {
        scanf("%lld %lld", &n, &b);
        long long s = n * (n + 1L) / 2L;
        while (s >= b) {
            long long tmp = 0L;
            while (s) {
                tmp += s % b;
                s /= b;
            }
            s = tmp;
        }
        if (s < 10)
            printf("%lld\n", s);
        else
            printf("%c\n", 'A' + s - 10);
    }
    return 0;
}
