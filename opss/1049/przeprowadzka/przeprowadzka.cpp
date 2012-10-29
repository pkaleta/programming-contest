#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

int t[MAX_N];
int n, k;

bool check(int limit) {
    int i = 0;
    int sum = 0;
    int tmp = 1;
    while (i < n) {
        if (sum + t[i] <= limit)
            sum += t[i];
        else {
            sum = t[i];
            if (++tmp > k)
                return false;
        }
        ++i;
    }
    return true;
}

int lower_bound(int l, int r) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (check(m)) {
            if (l + 1 == r)
                return l;
            r = m;
        }
        else {
            if (l + 1 == r)
                return r;
            l = m;
        }
    }
    return l;
}

int main() {
    int s = 0;
    int m = 0;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
        s += t[i];
        m = max(m, t[i]);
    }
    printf("%d\n", lower_bound(m, s));

    return 0;
}
