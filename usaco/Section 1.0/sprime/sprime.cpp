/*
ID: piotrek4
LANG: C++
PROG: sprime
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
#include <cmath>

using namespace std;


ifstream fin("sprime.in");
ofstream fout("sprime.out");


vector<int> vs;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


void gen(int n, int curLen, int maxLen) {
    if (isPrime(n)) {
        if (curLen == maxLen) {
            vs.push_back(n);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            gen(n*10+i, curLen+1, maxLen);
        }
    }
}


int main() {
    int len;
    fin >> len;

    for (int i = 2; i < 10; ++i) {
        gen(i, 1, len);
    }
    sort(vs.begin(), vs.end());

    for (int i = 0; i < vs.size(); ++i) {
        fout << vs[i] << endl;
    }
    return 0;
}

