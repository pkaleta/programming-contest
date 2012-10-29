/*
ID: piotrek4
LANG: C++
PROG: namenum
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int key[256];

string keys(string s) {
    stringstream ss;
    for (int i = 0; i < s.size(); ++i) {
        ss << key[s[i]];
    }
    return ss.str();
}

int main() {
    string s;
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream dict("dict.txt");

    string al = "ABCDEFGHIJKLMNOPRSTUVWXY";
    for (char c = 'A'; c <= 'Z'; ++c) {
        key[c] = -1;
    }
    for (int i = 2, k = 0; i <= 9; ++i) {
        for (int j = 0; j < 3; ++j, ++k) {
            key[al[k]] = i;
        }
    }

    map<string, vector<string> > d;

    while (getline(dict, s)) {
        string ks = keys(s);
        if (d.find(ks) == d.end()) {
            d[ks] = vector<string>();
        }
        d[ks].push_back(s);
    }

    fin >> s;
    if (d.find(s) == d.end()) {
        fout << "NONE" << endl;
    } else {
        vector<string> tmp = d[s];
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); ++i) {
            fout << tmp[i] << endl;
        }
    }

    return 0;
}
