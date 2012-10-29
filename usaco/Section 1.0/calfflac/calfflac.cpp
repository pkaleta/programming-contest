/*
ID: piotrek4
LANG: C++
PROG: calfflac
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

ifstream fin("calfflac.in");
ofstream fout("calfflac.out");


const int MAX_LEN = 2005;


bool isPal(string& s, int a, int b) {
    for (int i = a; i < b; ++i) {
        if (s[i] != s[b-(i-a)-1]) {
            return false;
        }
    }

    return true;
}


int main() {
    string line;
    string s;
    string filt;
    stringstream ss;
    stringstream ss1;
    vector<int> p;
    int maxLen = 1;
    int maxStart = 0;
    int maxEnd = 0;

    while (getline(fin, s)) {
        ss << s << endl;
    }

    s = ss.str();

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ss1 << s[i];
            p.push_back(i);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            ss1 << char(s[i]+32);
            p.push_back(i);
        }
    }

    filt = ss1.str();

    int i = 0;
    while (i < filt.size()) {
        int a = i;
        int b = i+1;
        int maxFound = 0;
        while (b <= filt.size() && p[b]-p[a]+1 <= MAX_LEN) {
            if (isPal(filt, a, b)) {
                maxFound = max(maxFound, b-a);
                if (b-a > maxLen) {
                    maxLen = b-a;
                    maxStart = p[a];
                    maxEnd = p[b-1];
                }
            }
            ++b;
        }
        i += max(1, maxFound-1);
    }

    fout << maxLen << endl;
    for (int i = maxStart; i <= maxEnd; ++i) {
        fout << s[i];
    }
    fout << endl;

    return 0;
}
