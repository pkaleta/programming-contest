/*
ID: piotrek4
LANG: C++
PROG: prefix
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


ifstream fin("prefix.in");
ofstream fout("prefix.out");

const int MAX_LEN = 200005;


int dp[MAX_LEN];


int main() {
    string s;
    string line;
    vector<string> primitive;
    stringstream ss;

    fin >> s;
    while (s != ".") {
        primitive.push_back(s);
        fin >> s;
    }

    while (true) {
        fin >> line;
        if (fin.eof()) break;
        ss << line;
    }
    s = ss.str();

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < primitive.size(); ++j) {
            int start = i-primitive[j].size()+1;
            if (start >= 0 && s.substr(start, primitive[j].size()) == primitive[j] && dp[start]) {
                dp[i+1] = 1;
                ret = i+1;
            }
        }
    }

    fout << ret << endl;

    return 0;
}
