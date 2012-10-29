/*
ID: piotrek4
LANG: C++
PROG: zerosum
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


ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
vector<string> ret;
int n;
char mapping[3] = {'+', '-', ' '};

int calc(string s) {
    vector<char> op;
    vector<int> v;
    int acc = 1;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            v.push_back(acc);
            op.push_back(s[i]);
            acc = i+2;
        } else {
            acc = acc*10+i+2;
        }
    }
    v.push_back(acc);

    int ret = v[0];
    for (int i = 0; i < op.size(); ++i) {
        if (op[i] == '+') ret += v[i+1];
        else ret -= v[i+1];
    }
    return ret;
}

string makeStr(string s) {
    stringstream ss;
    ss << 1;
    for (int i = 0; i < s.size(); ++i) ss << s[i] << i+2;
    return ss.str();
}

void solve(string s) {
    if (s.size() == n-1) {
        if (calc(s) == 0) ret.push_back(makeStr(s));
        return;
    }

    for (int i = 0; i < 3; ++i) solve(s+mapping[i]);
}


int main() {
    fin >> n;
    solve("");
    sort(ret.begin(), ret.end());

    for (int i = 0; i < ret.size(); ++i) fout << ret[i] << endl;

    return 0;
}
