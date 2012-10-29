#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1005;

char s[MAXN];
int t[MAXN];
int n;

int lcs(int m) {
    int tmp1, tmp2;

    memset(t, 0, sizeof(t));

    for (int i = 1; i < m; ++i) {
        tmp1 = 0;
        for (int j = m; j <= n; ++j) {
            tmp2 = t[j];
            t[j] = max(t[j], t[j-1]);
            if (s[i] == s[j])
                t[j] = max(t[j], tmp1+1);
            tmp1 = tmp2;
        }
    }
    return t[n];
}

void read_data() {
    scanf("%d", &n);
    scanf("%s", s+1);
}

int calculate() {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result = max(result, lcs(i));
    }
    return n-2*result;
}

int main() {
    read_data();

    printf("%d\n", calculate());

    return 0;
}
