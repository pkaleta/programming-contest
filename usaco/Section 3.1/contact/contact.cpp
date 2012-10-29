/*
ID: piotrek4
LANG: C++
PROG: contact
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


ifstream fin("contact.in");
ofstream fout("contact.out");

int a, b, n;
stringstream ss;
vector<pair<int, string> > res;
map<string, int> m;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first > b.first) return true;
    if (a.first == b.first) {
        if (a.second.size() < b.second.size()) return true;
        if (a.second.size() > b.second.size()) return false;
        return a.second < b.second;
    }
    return false;
}

int main() {
    fin >> a >> b >> n;

    string tmp;
    while (true) {
        fin >> tmp;
        if (fin.eof()) break;
        ss << tmp;
    }

    string s = ss.str();

    for (int j = a; j <= b; ++j) {
        for (int i = 0; s.size() >= j && i < s.size()-j+1; ++i) {
            string x = s.substr(i, j);
            if (m.find(x) == m.end())
                m[x] = 0;
            ++m[x];
        }
    }

    int i = 0;
    int cnt = 0;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        res.push_back(make_pair(it->second, it->first));
    }
    sort(res.begin(), res.end(), cmp);
    while (cnt < n && i < res.size()) {
        int tmp = res[i].first;
        fout << res[i].first << endl;
        fout << res[i].second;
        ++i;
        int inLine = 1;
        while (i < res.size() && res[i].first == tmp) {
            if (inLine == 6) {
                inLine = 0;
                fout << "\n";
            } else if (inLine != 0)
                fout << " ";
            fout << res[i].second;
            ++i;
            inLine++;
        }
        fout << endl;
        ++cnt;
    }

    return 0;
}
