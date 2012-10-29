/*
ID: piotrek4
LANG: C++
PROG: clocks
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

ifstream fin("clocks.in");
ofstream fout("clocks.out");
int clocks[3][3];

typedef void (*moveFunPtr)(int[3][3]);


void inc(int a[3][3], int x, int y) {
    a[y][x] = (a[y][x]+3)%12;
}

void move1(int a[3][3]) {
    inc(a, 0, 0); inc(a, 1, 0); inc(a, 0, 1); inc(a, 1, 1);
}

void move2(int a[3][3]) {
    inc(a, 0, 0); inc(a, 1, 0); inc(a, 2, 0);
}

void move3(int a[3][3]) {
    inc(a, 1, 0); inc(a, 2, 0); inc(a, 1, 1); inc(a, 2, 1);
}

void move4(int a[3][3]) {
    inc(a, 0, 0); inc(a, 0, 1); inc(a, 0, 2);
}

void move5(int a[3][3]) {
    inc(a, 1, 0); inc(a, 0, 1); inc(a, 1, 1); inc(a, 2, 1); inc(a, 1, 2);
}

void move6(int a[3][3]) {
    inc(a, 2, 0); inc(a, 2, 1); inc(a, 2, 2);
}

void move7(int a[3][3]) {
    inc(a, 0, 1); inc(a, 1, 1); inc(a, 0, 2); inc(a, 1, 2);
}

void move8(int a[3][3]) {
    inc(a, 0, 2); inc(a, 1, 2); inc(a, 2, 2);
}

void move9(int a[3][3]) {
    inc(a, 1, 1); inc(a, 2, 1); inc(a, 1, 2); inc(a, 2, 2);
}

moveFunPtr move[10] = {NULL, &move1, &move2, &move3, &move4, &move5, &move6, &move7, &move8, &move9};

bool check(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    int tmp[3][3];
    int mnum[10];

    memcpy(tmp, clocks, sizeof(clocks));

    mnum[1] = a; mnum[2] = b; mnum[3] = c;
    mnum[4] = d; mnum[5] = e; mnum[6] = f;
    mnum[7] = g; mnum[8] = h; mnum[9] = i;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j < mnum[i]; ++j) {
            move[i](tmp);
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tmp[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    int minMoves = 1 << 30;
    int moves[10];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x;
            fin >> x;
            clocks[i][j] = x % 12;
        }
    }

    for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) {
            for (int c = 0; c < 4; ++c) {
                for (int d = 0; d < 4; ++d) {
                    for (int e = 0; e < 4; ++e) {
                        for (int f = 0; f < 4; ++f) {
                            for (int g = 0; g < 4; ++g) {
                                for (int h = 0; h < 4; ++h) {
                                    for (int i = 0; i < 4; ++i) {
                                        if (check(a, b, c, d, e, f, g, h, i)) {
                                            int sum = a+b+c+d+e+f+g+h+i;

                                            if (sum < minMoves) {
                                                minMoves = sum;

                                                moves[1] = a; moves[2] = b; moves[3] = c;
                                                moves[4] = d; moves[5] = e; moves[6] = f;
                                                moves[7] = g; moves[8] = h; moves[9] = i;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    stringstream ss;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j < moves[i]; ++j) {
            ss << i << " ";
        }
    }

    string ret = ss.str();
    ret = ret.substr(0, ret.size()-1);
    fout << ret << endl;

    return 0;
}
