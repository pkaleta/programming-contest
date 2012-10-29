#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

const int MAX_N = 10000;

int* generate_primes(int& len) {
    bool tmp[MAX_N];
    int* primes;
    memset(tmp, 0, sizeof(tmp));
    tmp[0] = tmp[1] = true;
    len = 0;
    for (int i = 2; i < MAX_N; ++i)
        if (!tmp[i]) {
            int j = i * 2;
            ++len;
            while (j < MAX_N) {
                tmp[j] = true;
                j += i;
            }
        }
    primes = (int*) malloc(sizeof(int) * len);
    int j = 0;
    for (int i = 0; i < MAX_N; ++i)
        if (!tmp[i])
            primes[j++] = i;
    return primes;
}

int main() {
    int a;
    int len;
    int* primes;
    primes = generate_primes(len);
    int factors[MAX_N];
    memset(factors, 0, sizeof(int) * MAX_N);

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &a);
        int j = 0;
        while (a > 1) {
            while (a > 1 && a % primes[j] == 0) {
                ++factors[primes[j]];
                a /= primes[j];
            }
            ++j;
        }
    }
    int r = 1;
    for (int i = 0; i < len; ++i)
        if (factors[primes[i]])
            r = r * (factors[primes[i]] + 1) % 10;
    printf("%d\n", r);
}
