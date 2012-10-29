/*
ID: piotrek4
LANG: C++
PROG: hamming
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


const int MAX_N = 300;


ifstream fin("hamming.in");
ofstream fout("hamming.out");
int n, b, d;
vector<int> res;


int calcDist(int a, int b) {
    int ret = 0;
    while (a || b) {
        if (a%2 != b%2) ++ret;
        a >>= 1;
        b >>= 1;
    }
    return ret;
}


int main() {
    fin >> n >> b >> d;

    res.push_back(0);
    int i = 1;
    while (res.size() < n) {
        bool hamming = true;
        for (int j = 0; j < res.size(); ++j) {
            if (calcDist(i, res[j]) < d) {
                hamming = false;
                break;
            }
        }
        if (hamming) res.push_back(i);
        ++i;
    }
    for (int i = 0; i < res.size(); ++i) {
        fout << res[i];
        if (i < res.size()-1) {
            if ((i+1)%10 == 0) fout << endl;
            else fout << " ";
        }
    }
    fout << endl;
    return 0;
}
