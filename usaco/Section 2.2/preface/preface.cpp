/*
ID: piotrek4
LANG: C++
PROG: preface
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


ifstream fin("preface.in");
ofstream fout("preface.out");
string l = "MDCLXVI";


bool isPower10(int n) {
    return n == 1000 || n == 100 || n == 10 || n == 1;
}


string roman(int n) {
    int v[7] = {1000, 500, 100, 50, 10, 5, 1};
    string ret = "";

    for (int i = 0; i < 7 && n; ++i) {
        if (n >= v[i]) {
            int d = n / v[i];
            for (int j = 0; j < d; ++j) {
                ret += l[i];
            }
            n %= v[i];
        }
        for (int j = min(6, i+2); j > i ; --j) {
            if (isPower10(v[j]) && n >= v[i]-v[j]) {
                ret += l[j];
                ret += l[i];
                n -= v[i] - v[j];
                break;
            }
        }
    }
    return ret;
}


int main() {
    int n;
    int count[256];

    memset(count, 0, sizeof(count));

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        string s = roman(i);
        for (int j = 0; j < s.size(); ++j) {
            ++count[s[j]];
        }
    }
    for (int i = l.size()-1; i >= 0; --i) {
        if (count[l[i]] > 0) fout << l[i] << " " << count[l[i]] << endl;
    }

    return 0;
}
