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
    scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);

    find(4);
    find(7);

    sort(lucky.begin(), lucky.end());
    lucky.push_back(2000000000);
//    for (int i = 0; i < lucky.size(); ++i)
//        cout << lucky[i] << endl;


//    int ps = lower_bound(lucky.begin(), lucky.end(), pl)-lucky.begin();
//    int pe = lower_bound(lucky.begin(), lucky.end(), pr)-lucky.begin();
//    if (ps < pe && lucky[pe] != pr) --pe;
//
//
//    int vs = lower_bound(lucky.begin(), lucky.end(), vl)-lucky.begin();
//    int ve = lower_bound(lucky.begin(), lucky.end(), vr)-lucky.begin();
//    if (vs > 0 && lucky[vs] != vl) --vs;
//    if (ve > 0 && lucky[ve] != vr) --ve;

    int ps, pe; ps = pe = 0;
    while (pl > lucky[ps]) ++ps;
    while (pr >= lucky[pe]) ++pe;
    if (ps != pe) --pe;

    int vs, ve; vs = ve = 0;
    while (vl >= lucky[vs]) ++vs;
    while (vr >= lucky[ve]) ++ve;
    if (vs == ve) --vs;
    --ve;


    cout << ps << " " << pe << endl;
    cout << vs << " " << ve << endl;
    cout << "**************" << endl;

    if (pe-ps == k) {
        if (vs > pe) {
            int left, right;
            if (ps == 0) left = lucky[ps];
            else left = lucky[ps]-lucky[ps-1];

            right = lucky[vs]-vl;
            good += left * right;
        } else {

        }
   }
    for (int i = ps; i <= pe; ++i) {
        for (int j = vs; j <= ve; ++j) {
            if (j-i+1 == k) {
                int left, right;
                if (i == ps) left = min(lucky[i], pr)-pl+1;
                else left = min(lucky[i], pr)-pl+1;//max(lucky[i-1], pl-1);

                if (i == pe) right = vr-max(lucky[j], vl)+1;
                else right = min(vr+1, lucky[j+1])-max(lucky[j], vl);
                cout << lucky[i] << " " << lucky[j] << endl;
                cout << left << " " << right << endl;

                good += left * right;
            }
            if (i-j+1 == k) {
                int left, right;
                if (j == vs) left = min(lucky[j], vr)-vl+1;
                else left = min(lucky[j], vr)-max(lucky[j-1], vl-1);

                if (j == ve) right = pr-max(lucky[i], pl)+1;
                else right = min(pr+1, lucky[i+1])-max(lucky[i], pl);

                good += left * right;
            }
        }
    }

//    cout << "**************** " << good << endl;

    double ret = (double)good / ((double)(pr-pl+1) * (double)(vr-vl+1)) ;

//    cout << ret << endl;
    printf("%.12lf\n", ret);

    return 0;
}
