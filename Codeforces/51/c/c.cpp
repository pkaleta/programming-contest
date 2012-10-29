#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    int m;
    int k;
    int x;
    int y;

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x, &y);
        if (x <= 5 || n-x <= 4 || y <= 5 || m-y <= 4) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
