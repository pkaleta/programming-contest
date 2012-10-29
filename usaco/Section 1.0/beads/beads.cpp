/*
ID: piotrek4
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    string s;

    fin >> n >> s;

    int res = 0;
    bool diff = s[0] == s[n-1];
    for (int i = 1; i < n; ++i) {
        diff = diff && (s[i] == s[i-1]);
    }
    if (diff) {
        res = n;
    }
    else {
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            int j = i;
            int firstRun;
            char tmp;

            if (s[i] != 'w')
                tmp = s[i];
            else {
                if (j == 0) j = n-1;
                else --j;
                while (j != i && s[j] == 'w') {
                    if (j == 0) j = n-1;
                    else --j;
                }
                tmp = s[j];
            }

            j = i;
            do {
                cur++;
                if (j == 0) j = n-1;
                else --j;
            }
            while (j != i && (s[j] == tmp || s[j] == 'w'));
            firstRun = j+1;

            if (cur < n) {
                int stop;
                if (i == n-1) j = 0;
                else j = i+1;
                stop = j;

                if (s[j] != 'w')
                    tmp = s[j];
                else {
                    if (j == n-1) j = 0;
                    else ++j;
                    while (j != stop && s[j] == 'w') {
                        if (j == n-1) j = 0;
                        else ++j;
                    }
                    tmp = s[j];
                }

                j = stop;
                do {
                    cur++;
                    if (j == n-1) j = 0;
                    else ++j;
                } while ((j != stop && j != firstRun) && (s[j] == tmp || s[j] == 'w'));
            }
            res = max(res, cur);
        }
    }

    fout << res << endl;

    return 0;
}
