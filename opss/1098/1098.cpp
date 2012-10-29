#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long n[10];
int found;

bool check(int t[10], int len) {
    int count[10];
    memset(count, 0, sizeof(int) * 10);
    for (int i = 0; i < len; ++i)
        ++count[t[i]];
    for (int i = 0; i < len; ++i)
        if (count[i] != t[i])
            return false;
    return true;
}

void generate(int t[10], int len, int left, int sum) {
    if (left == 0) {
        if (check(t, len)) {
            long long m = 1;
            for (int i = len - 1; i >= 0; --i) {
                n[found] += m * t[i];
                m *= 10;
            }
            ++found;
        }
    }
    else {
        int range = min(9, len - sum);
        for (int i = 0; i <= range; ++i) {
            t[len - left] = i;
            generate(t, len, left - 1, sum + i);
        }
    }
}

void initialize() {
    for (int len = 1; len <= 10; ++len) {
        int t[10];
        generate(t, len, len, 0);
    }
}

int main() {
    int d;
    long long x;

    initialize();
    scanf("%d", &d);
    while (d--) {
        scanf("%lld", &x);
        int i = 0;
        while (i < found && n[i] <= x)
            ++i;
        --i;
        if (i < 0)
            printf("-1\n");
        else
            printf("%lld\n", n[i]);
    }

    return 0;
}
