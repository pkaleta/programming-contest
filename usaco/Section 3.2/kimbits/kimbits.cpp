/*
ID: piotrek4
LANG: C++
PROG: kimbits
*/

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

const int MAX_N = 35;
const int MAX_M = 35;


ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
long long N, L, I;
int size[MAX_N][MAX_M];

void calcSetSize() {
    for (int i = 0; i <= N; ++i)
        size[0][i] = 1;
    for (int i = 1; i <= N; ++i) {
        size[i][0] = 1;
        for (int j = 1; j <= N; ++j)
            size[i][j] += size[i-1][j]+size[i-1][j-1];
    }
}

void search(int b, int o, long long i) {
    if (b == 0) return;

    int s = size[b-1][o];
    if (i < s) {
        fout << "0";
        search(b-1, o, i);
    } else {
        fout << "1";
        search(b-1, o-1, i-s);
    }
}

int main() {
    fin >> N >> L >> I;
    calcSetSize();
    search(N, L, I-1);
    fout << endl;

    return 0;
}
