#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

double calc(int station, int i) {
    return ((float)(station) * 10.0f) / (float)(i + 1);
}

int main() {
    double lb = 0.0f;
    double ub = 0.0f;
    int n;
    int s[MAX_N];
    int prevStation;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }
    ub = n*10.0f;

    int curStationNum = 1;
    for (int i = 0; i < n; ++i) {
        while (curStationNum != s[i]) {
            lb = max(lb, calc(curStationNum+1, i));
            ++curStationNum;
        }

        ub = min(ub, calc(s[i]+1, i));
    }

    int minAmountLeft = int(lb * (n+1) - s[n-1] * 10.0f) / 10;
    int maxAmountLeft = int(ub * (n+1) - s[n-1] * 10.0f) / 10;

    if (minAmountLeft == maxAmountLeft) {
        printf("unique\n%d\n", s[n-1] + minAmountLeft);
    } else {
        printf("not unique\n");
    }

    return 0;
}
