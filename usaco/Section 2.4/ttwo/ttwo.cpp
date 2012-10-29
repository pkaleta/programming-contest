/*
ID: piotrek4
LANG: C++
PROG: ttwo
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

const int SIZE = 10;
const int MAX_MOVES = 160000;


ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
list<int> ftimes[SIZE][SIZE];
list<int> ctimes[SIZE][SIZE];
vector<string> grid;
//0 - up
//1 - right
//2 - down
//3 - left


bool check(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && grid[y][x] != '*';
}

void makeMove(int& x, int& y, int& dir) {
    if (dir == 0 && check(x, y-1)) --y;
    else if (dir == 1 && check(x+1, y)) ++x;
    else if (dir == 2 && check(x, y+1)) ++y;
    else if (dir == 3 && check(x-1, y)) --x;
    else dir = (dir+1)%4;
}

int main() {
    char c;
    int cx, cy, fx, fy;
    int cdir, fdir;
    string line;

    for (int i = 0; i < SIZE; ++i) {
        fin >> line;
        grid.push_back(line);

        for (int j = 0; j < SIZE; ++j) {
            if (line[j] == 'C') {
                cx = j;
                cy = i;
            }
            else if (line[j] == 'F') {
                fx = j;
                fy = i;
            }
        }
    }

    int move = 0;
    cdir = fdir = 0;
    while (move <= MAX_MOVES && (fx != cx || fy != cy)) {
        makeMove(cx, cy, cdir);
        makeMove(fx, fy, fdir);
        ++move;
    }

    if (move > MAX_MOVES) fout << 0 << endl;
    else fout << move << endl;

    return 0;
}
