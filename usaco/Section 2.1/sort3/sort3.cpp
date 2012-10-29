/*
ID: piotrek4
LANG: C++
PROG: sort3
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;


ifstream fin("sort3.in");
ofstream fout("sort3.out");


const int MAX_N = 1005;


int main() {
    int n;
    int a[MAX_N];
    int b[MAX_N];
    int ret = 0;
    int cnt[3] = {0, 0, 0};

    fin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        a[i] = b[i] = x-1;
        cnt[x-1]++;
    }

    sort(b, b+n);

    int s = 0;
    for (int i = 0; i < 3; ++i) {
        sort(a+s, a+s+cnt[i]);
        s += cnt[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++ret;
            for (int j = i+1; j < n; ++j) {
                if (a[j] == b[i] && a[j] != b[j]) {
                    int tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                }
            }
        }
    }

    fout << ret << endl;;

    return 0;
}
