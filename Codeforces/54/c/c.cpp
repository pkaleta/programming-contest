#include <cstdio>
#include <cstring>

const int MAX_N = 100005;

int main() {
    int n;
    int a[MAX_N];
    int c[MAX_N];
    int result = 0;

    memset(c, 0, sizeof(c));
    scanf("%d", &n);
    int m = (n-1)/2;
    for (int i = 0; i <= m; ++i) {
        scanf("%d", &a[i]);
        int x = a[i]-i;
        if (x >= 0) {
            ++c[x];
        }
    }
    for (int i = m+1; i < n; ++i) {
        scanf("%d", &a[i]);
        int x = a[i]-(n-i)+1;
        if (x >= 0) {
            ++c[x];
        }
    }
    int a0 = -1;
    for (int i = 1; i < MAX_N; ++i) {
        if (c[i] > c[a0]) {
            a0 = i;
        }
    }
    for (int i = 0; i <= m; ++i) {
        if (a[i] != a0) {
            ++result;
        }
        ++a0;
    }
    if (n & 1) {
        a0 -= 2;
    } else {
        a0 -= 1;
    }
    for (int i = m+1; i < n; ++i) {
        if (a[i] != a0) {
            ++result;
        }
        --a0;
    }
    printf("%d\n", result);
}
