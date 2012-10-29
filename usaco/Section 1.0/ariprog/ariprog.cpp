/*
ID: piotrek4
LANG: C++
PROG: ariprog
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


const int MAX_M = 255;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

vector<int> bs;
vector<pair<int, int> > s;
bool isBisquare[125005];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second < b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return false;
    }
}

void generateBisquares(int m) {
    memset(isBisquare, 0, sizeof(isBisquare));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            int b = i*i+j*j;
            if (!isBisquare[b]) {
                bs.push_back(b);
                isBisquare[b] = true;
            }
        }
    }
    sort(bs.begin(), bs.end());
}

int main() {
    int n, m;
    fin >> n >> m;

    generateBisquares(m);

    for (int i = 0; i < bs.size(); ++i) {
        for (int j = i+1; j < bs.size(); ++j) {
            bool found = true;
            int diff = bs[j]-bs[i];
            if (bs[i]+diff*(n-1) > bs[bs.size()-1])
                break;
            for (int k = 1; k < n; ++k) {
                if (!isBisquare[bs[i]+diff*k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                s.push_back(make_pair(bs[i], diff));
            }
        }
    }

    if (s.empty()) {
        fout << "NONE" << endl;
    }
    else {
        sort(s.begin(), s.end(), cmp);
        for (int i = 0; i < s.size(); ++i) {
            fout << s[i].first << " " << s[i].second << endl;
        }
    }

    return 0;
}
