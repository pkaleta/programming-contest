/*
ID: piotrek4
LANG: C++
PROG: milk2
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first > b.first) {
        return false;
    } else {
        return a.second < b.second;
    }
}


int main() {
    int n;
    int a, b, s, e;
    vector<pair<int, int> > t;
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a >> b;
        t.push_back(make_pair(a, b));
    }
    sort(t.begin(), t.end(), cmp);
//    for (int i = 0; i < n; ++i) {
//        cout << t[i].first << " " << t[i].second << endl;
//    }

    int milking = 0;
    int noMilking = 0;
    int i = 0;
    while (i < t.size()) {
        s = t[i].first;
        e = t[i].second;
        while (i < t.size() && s <= t[i+1].first && t[i+1].first <= e) {
            e = max(e, t[i+1].second);
            ++i;
        }
        if (e-s > milking)
            milking = e-s;
        if (i < t.size()-1) {
            if (t[i+1].first-e > noMilking) {
                noMilking = t[i+1].first-e;
            }
        }
        ++i;
    }

    fout << milking << " " << noMilking << endl;

    return 0;
}
