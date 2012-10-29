#include <cstdio>
#include <cmath>

const int MAX_N = 14145;
const int MAX = 200000001;

long long t[MAX_N][2];
int length;

void initialize() {
    t[0][0] = 1;
    t[0][1] = 1;
    int i = 0;
    int diff = 1;
    length = 0;
    while (i * i < MAX) {
        ++i;
        t[i][0] = t[i - 1][0] + diff;
        diff += 2;
        t[i][1] = (i + 1) * (i + 1);
    }
    length = i;
}

int bs(long long x) {
    int l = 0;
    int r = length;
    long long m;
    while (1) {
        if (r - l == 1) {
            if (t[l][0] >= x && x <= t[l][1])
                return l;
            else if (t[r][0] >= x && x <= t[r][1])
                return r;
        }
        m = (l + r) / 2;
        if (x < t[m][0])
            r = m;
        else if (x > t[m][1])
            l = m;
        else
            return m;
    }
}

int main() {
    int d;
    long long k;
    initialize();
    scanf("%d", &d);
    while (d--) {
        scanf("%lld", &k);
        int i = bs(k);
        if (((k & 1) && (i & 1)) || (!(k & 1) && !(i & 1)))
            printf("-1\n");
        else {
            int x = (i + 1) * i / 2 + (k - t[i][0]) / 2 + 1;
            printf("%d\n", x);
        }
    }
    return 0;
}
