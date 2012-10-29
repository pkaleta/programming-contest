#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

const long long MAX_N = 1000000000LL;

vector<int> lucky;

void find(long long n) {
    if (n > MAX_N) return;
    lucky.push_back((int)n);

    find(n*10LL+4LL);
    find(n*10LL+7LL);
}


int main() {
    int pl, pr, vl, vr, k;
    long long good = 0;
    long long left, right;
    scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);

    find(4);
    find(7);

    sort(lucky.begin(), lucky.end());
    lucky.push_back(2000000000);

    for (int i = 0; i < lucky.size()-k+1; ++i) {
        if (lucky[i] >= pl && (i == 0 || pr >= lucky[i-1]) && lucky[i+k-1] <= vr && vl < lucky[i+k]) {
            if (i == 0) left = lucky[i]-pl+1;
            else left = min(lucky[i], pr)-max(pl-1, lucky[i-1]);

            if (i == lucky.size()-k+1) right = vr-lucky[i+k-1]+1;
            else right = min(lucky[i+k], vr+1)-max(lucky[i+k-1], vl);

            good += left * right;
        }

        if (lucky[i] >= vl && (i == 0 || vr >= lucky[i-1])  && lucky[i+k-1] <= pr && pl < lucky[i+k]) {
            if (i == 0) left = lucky[i]-vl+1;
            else left = min(lucky[i], vr)-max(vl-1, lucky[i-1]);

            if (i == lucky.size()-k+1) right = pr-lucky[i+k-1]+1;
            else right = min(lucky[i+k], pr+1)-max(lucky[i+k-1], pl);

            good += left * right;
            if (lucky[i] == lucky[i+k-1]) --good;
        }
    }

    double ret = (double)good / ((double)(pr-pl+1) * (double)(vr-vl+1)) ;

    printf("%.12lf\n", ret);

    return 0;
}
