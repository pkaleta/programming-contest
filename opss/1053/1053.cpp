#include <cstdio>
#include <cmath>
#include <algorithm>
#define PHI (1.0 + sqrtl(5)) / 2.0

using namespace std;


int main() {
    int d;
    long double l;

    scanf("%d", &d);
    while (d--) {
        scanf("%llf", &l);
        l *= 12.0;
        long double x = log10l(PHI + 2) - log10l(2 * PHI - 1) + l * log10l(PHI);
        int digits = ((int) x) + 1;
        long double f = x - ((int) trunc(x));
        long double num = powl(10, f) * 1000000000;
        long long div = 1000000000LL / ((long long) powl(10, digits - 1));
        if (div == 0)
            printf("%d %lld\n", digits, (long long) num);
        else
            printf("%d %lld\n", digits, (long long) num / div);
    }
    return 0;
}
