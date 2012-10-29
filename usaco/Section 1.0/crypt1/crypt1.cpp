/*
ID: piotrek4
LANG: C++
PROG: crypt1
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

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");


bool check(vector<int>& dig, int n) {
    while (n > 0) {
        int d = n % 10;
        n /= 10;

        bool found = false;
        for (int i = 0; i < dig.size(); ++i) {
            if (d == dig[i]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}


int main() {
    int n;
    vector<int> dig;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        dig.push_back(x);
    }

    int sol = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                for (int d = 0; d < n; ++d) {
                    for (int e = 0; e < n; ++e) {
                        int A = dig[a]*100 + dig[b]*10 + dig[c];
                        int C = A*dig[e];
                        int D = A*dig[d];
                        if (C > 999 || D > 999) continue;
                        if (!check(dig, C) || !check(dig, D)) continue;
                        int E = C+D*10;
                        if (E > 9999) continue;
                        if (!check(dig, E)) continue;
                        sol++;
                    }
                }
            }
        }
    }

    fout << sol << endl;

    return 0;
}
