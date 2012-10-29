#include <cstdio>

const int MAX_N = 1000005;

int d[MAX_N];
long long result[MAX_N];

int f(int n) {
    if (n < 10)
        return n;
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return f(s);
}

void init() {
    for (int i = 0; i < MAX_N; ++i)
        d[i] = f(i);
}

int main() {
    int n;

    init();

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int x = d[i];
        result[i] = result[i-1];
        for (int j = 1; j < i; ++j) {
            int tmp = d[x*d[j]];
            if (tmp <= i && (long long)i*(long long)j != tmp)
                result[i] += 2;
        }
        int tmp = d[x*x];
        if (tmp <= i && i*i != tmp)
            ++result[i];
    }

    printf("%lld\n", result[n]);
    return 0;
}
