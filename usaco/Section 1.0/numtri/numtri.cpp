/*
ID: piotrek4
LANG: C++
PROG: numtri
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


ifstream fin("numtri.in");
ofstream fout("numtri.out");


const int MAX_R = 1005;


int main() {
    int r;
    int prev, tmp;
    vector<int> cur(MAX_R);
    int ret = -1;

    fin >> r;

    for (int i = 0; i < r; ++i) {
        prev = 0;
        for (int j = 0; j < i+1; ++j) {
            tmp = cur[j];
            fin >> cur[j];

            cur[j] += max(tmp, prev);
            ret = max(ret, cur[j]);
            prev = tmp;
        }
    }

    fout << ret << endl;


    return 0;
}
