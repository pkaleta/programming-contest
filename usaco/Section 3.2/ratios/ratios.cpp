/*
ID: piotrek4
LANG: C++
PROG: ratios
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


ifstream fin("ratios.in");
ofstream fout("ratios.out");

int goal[3];
int feed[3][3];

int main() {
    for (int i = 0; i < 3; ++i)
        fin >> goal[i];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            fin >> feed[i][j];

    int cur[3];
    int mini, minj, mink;
    mini = minj = mink = 105;
    int mul = -1;
    int m[1000];

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                bool check = true;
                memset(m, 0, sizeof(m));
                int nother = 0;
                int nzero = 0;

                for (int l = 0; l < 3; ++l) {
                    cur[l] = i*feed[0][l] + j*feed[1][l] + k*feed[2][l];
                    if (goal[l] == 0) {
                        check = check && cur[l] == 0;
                        ++nzero;
                    }
                    else {
                        check = check && (cur[l] % goal[l] == 0);
                        if (m[cur[l] / goal[l]] == 0) {
                            m[cur[l] / goal[l]] = 1;
                            ++nother;
                        }
                    }
                }
                if (check && nother <= 1) {
                    if (i + j + k < mini + minj + mink && (i > 0 || j > 0 || k > 0)) {
                        mini = i; minj = j; mink = k;
                        mul = cur[0] / goal[0];
                    }
                }
            }
        }
    }

    if (mul == -1)
        fout << "NONE" << endl;
    else
        fout << mini << " " << minj << " " << mink << " " << mul << endl;

    return 0;
}
