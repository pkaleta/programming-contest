/*
ID: piotrek4
LANG: C++
PROG: lamps
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


ifstream fin("lamps.in");
ofstream fout("lamps.out");

const int MAX_N = 105;

bool cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
}

int main() {
    int n, c, i;
    vector<int> on;
    vector<int> off;
    vector<vector<int> > sol;

    fin >> n >> c >> i;
    while (i != -1) {
        on.push_back(i);
        fin >> i;
    }
    fin >> i;
    while (i != -1) {
        for (int j = 0; j < on.size(); ++j) {
            if (on[j] == i) {
                fout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
        off.push_back(i);
        fin >> i;
    }

    bool lamps[MAX_N];
    for (int b1 = 0; b1 <= 1; ++b1) {
        for (int b2 = 0; b2 <= 1; ++b2) {
            for (int b3 = 0; b3 <= 1; ++b3) {
                for (int b4 = 0; b4 <= 1; ++b4) {
                    int s = b1+b2+b3+b4;
                    if (s <= c && c%2 == s%2) {
                        for (int i = 1; i <= n; ++i) lamps[i] = true;
                        if (b1) for (int i = 1; i <= n; ++i) lamps[i] = !lamps[i];
                        if (b2) for (int i = 1; i <= n; i += 2) lamps[i] = !lamps[i];
                        if (b3) for (int i = 2; i <= n; i += 2) lamps[i] = !lamps[i];
                        if (b4) for (int i = 1; i <= n; i += 3) lamps[i] = !lamps[i];
                        bool pass = true;
                        for (int i = 0; i < on.size(); ++i) {
                            if (!lamps[on[i]]) {
                                pass = false;
                                break;
                            }
                        }
                        for (int i = 0; i < off.size(); ++i) {
                            if (lamps[off[i]]) {
                                pass = false;
                                break;
                            }
                        }

                        if (pass) {
                            vector<int> s(lamps+1, lamps+n+1);
                            sol.push_back(s);
                        }
                    }
                }
            }
        }
    }
    if (sol.empty())
        fout << "IMPOSSIBLE" << endl;
    else {
        sort(sol.begin(), sol.end(), cmp);
        for (int i = 0; i < sol.size(); ++i) {
            stringstream ss;
            for (int j = 0; j < sol[i].size(); ++j) ss << (int)sol[i][j];
            fout << ss.str() << endl;
        }
    }
    return 0;
}
