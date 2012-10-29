/*
ID: piotrek4
LANG: C++
PROG: checker
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


ifstream fin("checker.in");
ofstream fout("checker.out");


const int MAX_N = 15;

struct Board {
    Board() {
        size = 0;
        memset(row, 0, sizeof(row));
        memset(mask, 0, sizeof(mask));
    }
    short size;
    char row[MAX_N];
    char mask[MAX_N][MAX_N];
};

vector<Board> sol;
int sols = 0;
int n;

bool cmp(Board a, Board b) {
    for (int i = 0; i < a.size; ++i) {
        if (a.row[i] < b.row[i]) return true;
        if (a.row[i] > b.row[i]) return false;
    }
}


void mark(Board& b, int r) {
    for (int i = b.size+1; i < n; ++i) {
        int diff = i-b.size;
        b.mask[r][i]++;
        if (r-diff >= 1) b.mask[r-diff][i]++;
        if (r+diff <= n) b.mask[r+diff][i]++;
    }
    b.row[b.size++] = r;
}

void unmark(Board& b, int r) {
    --b.size;
    for (int i = b.size+1; i < n; ++i) {
        int diff = i-b.size;
        b.mask[r][i]--;
        if (r-diff >= 1) b.mask[r-diff][i]--;
        if (r+diff <= n) b.mask[r+diff][i]--;
    }
}


void calc(Board& b) {
    if (b.size == n) {
        ++sols;
        if (sols < 4) sol.push_back(b);
        return;
    }
    for (int r = 1; r <= n; ++r) {
        if (b.mask[r][b.size] == 0) {
            mark(b, r);
            calc(b);
            unmark(b, r);
        }
    }
}


int main() {
    fin >> n;
    Board start;

    calc(start);

    for (int i = 0; i < sol.size(); ++i) {
        for (int j = 0; j < sol[i].size; ++j) {
            fout << (int)sol[i].row[j];
            if (j < sol[i].size-1) fout << " ";
        }
        fout << endl;
    }
    fout << sols << endl;
    return 0;
}
