#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int n, t;
int m[MAXN];

void read_data() {
    scanf("%d%d", &n, &t);

    for (int i = 0; i < n; ++i)
        scanf("%d", &m[i]);
}

long long calc() {
    if (n == 1)
        return ((t/2)+1)*(long long)m[0];

    long long s, result, tmp, r, l;
    s = result = m[0];

    for (int i = 1; i <= t && i < n; ++i) {
        s += (long long)m[i];
        l = (t-i+1)/2;
        r = (t-i)/2;
        tmp = s+l*(long long)m[i-1]+r*(long long)m[i];
        result = max(result, tmp);
    }
    return result;
}

int main() {
    read_data();

    printf("%lld\n", calc());

    return 0;
}
