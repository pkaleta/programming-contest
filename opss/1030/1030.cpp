#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 105;
const int MAX_WEIGHT = 1005;
const int MAX_WW = 105;

int t[MAX_WEIGHT * MAX_WW];
int w[MAX_N];
int ww, n;

bool check(int left) {
    if (t[left] == -1) {
        bool tmp = false;
        for (int i = 0; i < n; ++i) {
            if (left - w[i] >= 0)
                tmp |= check(min(left - w[i], w[i] * (ww - 1)));
        }
        t[left] = !tmp;
    }
    return t[left];
}

int main() {
    int c;

    scanf("%d", &c);
    while (c--) {
        for (int i = 0; i < MAX_WEIGHT * MAX_WW; ++i)
            t[i] = -1;
        t[0] = true;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &w[i]);
        scanf("%d", &ww);

        bool result = false;
        for (int i = 0; i < n; ++i)
            result |= check(w[i] * (ww - 1));

        if (result)
            printf("tak\n");
        else
            printf("nie\n");
    }
    return 0;
}
