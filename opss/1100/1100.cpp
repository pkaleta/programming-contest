#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
    int a, b, c;
    int l;
    scanf("%d", &l);
    while (l--) {
        scanf("%d", &c);
        int res = -1;
        if (c == 0)
            res = 0;
        else if (c % 2 == 0 && c % 4 != 0)
            res = -1;
        else {
            int r = (int) sqrt(c);
            int x = 1;
            while (x <= r && res == -1) {
                int y = c / x;
                if (x * y == c && !((x + y) & 1)) {
                    if (!((x + y) & 1) && !((x - y) & 1)) {
                        int a = abs((x + y) >> 1);
                        int b = abs(a - y);
                        res = b;
                    }
                }
                ++x;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
