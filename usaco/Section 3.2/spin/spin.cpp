/*
ID: piotrek4
LANG: C++
PROG: spin
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


ifstream fin("spin.in");
ofstream fout("spin.out");

class Wedge {
    public:
        Wedge() {}
        Wedge(int start, int ext) {
            this->start = start;
            this->ext = ext;
        }
        int start, ext;
};

const int NWHEELS = 5;
const int MAX_WEDGES = 5;

int speed[NWHEELS];
int nwedge[NWHEELS];
int pos[NWHEELS];
Wedge wedge[NWHEELS][MAX_WEDGES];

bool align() {
    int a[360];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < NWHEELS; ++i) {
        for (int j = 0; j < nwedge[i]; ++j) {
            int start = pos[i] + wedge[i][j].start;
            int end = start + wedge[i][j].ext;
            for (int k = start; k <= end; ++k) {
                ++a[k % 360];
            }
        }
    }

    for (int i = 0; i < 360; ++i) {
        if (a[i] >= NWHEELS)
            return true;
    }
    return false;
}

int main() {
    int start, ext;
    for (int i = 0; i < NWHEELS; ++i) {
        fin >> speed[i] >> nwedge[i];
        for (int j = 0; j < nwedge[i]; ++j)
            fin >> wedge[i][j].start >> wedge[i][j].ext;
    }

    int t = 0;
    while (t <= 360) {
        if (align()) {
            fout << t << endl;
            return 0;
        }

        for (int i = 0; i < NWHEELS; ++i) {
            pos[i] = (pos[i] + speed[i]) % 360;
        }
        ++t;
    }

    fout << "none" << endl;
    return 0;
}
