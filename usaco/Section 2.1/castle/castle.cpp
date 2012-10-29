/*
ID: piotrek4
LANG: C++
PROG: castle
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


ifstream fin("castle.in");
ofstream fout("castle.out");


const int MAX_SIZE = 55;
int c[MAX_SIZE][MAX_SIZE];
int comp[MAX_SIZE][MAX_SIZE];
int m, n;
int area[MAX_SIZE*MAX_SIZE];


bool left(int x, int y) { return (c[y][x] & 1) == 0; }

bool up(int x, int y) { return (c[y][x] & 2) == 0; }

bool right(int x, int y) { return (c[y][x] & 4) == 0; }

bool down(int x, int y) { return (c[y][x] & 8) == 0; }

int markComponent(int x, int y, int cnum) {
    if (x < 0 || x >= m) return 0;
    if (y < 0 || y >= n) return 0;
    if (comp[y][x] != 0) return 0;

    int ret = 1;
    comp[y][x] = cnum;

    if (left(x, y))  ret += markComponent(x-1, y, cnum);
    if (up(x, y))    ret += markComponent(x, y-1, cnum);
    if (right(x, y)) ret += markComponent(x+1, y, cnum);
    if (down(x, y))  ret += markComponent(x, y+1, cnum);

    return ret;
}

int findResult() {
    int rx;
    int ry;
    int rarea = 0;
    char rdir;
    int tmp;

    for (int x = 0; x <= m-1; ++x) {
        for (int y = n-1; y >= 0; --y) {
            int c = comp[y][x];

//            cout << y+1 << ", " << x+1 << " area: " << area[c] + area[cu] << " components: " << c << ", " << cu << endl;
            if (y > 0) {
                int cu = comp[y-1][x];
                if (cu != c) {
                    if ((tmp = area[c] + area[cu]) > rarea) {
                        rarea = tmp;
                        rx = x;
                        ry = y;
                        rdir = 'N';
                    }
                }
            }

            int cr = comp[y][x+1];
            if (cr != c) {
                if ((tmp = area[c] + area[cr]) > rarea) {
                    rarea = tmp;
                    rx = x;
                    ry = y;
                    rdir = 'E';
                }
            }
        }
    }

    fout << rarea << endl << ry+1 << " " << rx+1 << " " << rdir << endl;
}

int main() {
    fin >> m >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fin >> c[i][j];
        }
    }

    memset(area, 0, sizeof(area));
    memset(comp, 0, sizeof(comp));

    int cnum = 1;
    int maxRoom = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (comp[i][j] == 0) {
                area[cnum] = markComponent(j, i, cnum);
                maxRoom = max(maxRoom, area[cnum++]);
            }
        }
    }

    fout << cnum-1 << endl << maxRoom << endl;
    findResult();

//    for (int x = 0; x < m; ++x) {
//        cout << "##";
//    }
//    cout << "#" << endl;
//    for (int y = 0; y < n; ++y) {
//        for (int x = 0; x < m; ++x) {
//            if (!left(x, y)) {
//                cout << "#" << comp[y][x];
//            } else {
//                cout << "|" << comp[y][x];
//            }
//        }
//        cout << "#" << endl;
//        for (int x = 0; x < m; ++x) {
//            if (x == 0) {
//                if (!down(x, y)) {
//                    cout << "##";
//                } else {
//                    cout << "#-";
//                }
//
//            } else {
//                if (!down(x, y)) {
//                    cout << "##";
//                } else {
//                    if (!left(x, y)) {
//                        cout << "#-";
//                    } else {
//                        if (!down(x-1, y)) {
//                            cout << "#-";
//                        } else {
//                            cout << "--";
//                        }
//                    }
//                }
//            }
//        }
//        cout << "#" << endl;
//    }


    return 0;
}
