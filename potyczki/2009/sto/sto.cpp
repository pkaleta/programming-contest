#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    const int MAX_N = 1001;

    int n, k, s;
    int a[MAX_N];
    int l;
    int c = 0;
    int r = 0;

    scanf("%d %d %d", &n, &k, &s);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    l = k * s;
    sort(a, a + n, greater<int>());

    while (c < l)
        c += a[r++];
    printf("%d\n", r);

    return 0;
}
