/*
ID: piotrek4
LANG: C++
PROG: milk3
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

ifstream fin("milk3.in");
ofstream fout("milk3.out");

vector<int> res;
bool vis[25][25][25];
int ac, bc, cc;
bool found[25];


void calc(int a, int b, int c) {
    int x;

    if (a == 0) {
        if (!found[c]) {
            res.push_back(c);
            found[c] = true;
        }
    }
    if (vis[a][b][c]) return;

    vis[a][b][c] = true;

    x = min(ac-a, c);
    calc(a+x, b, c-x);

    x = min(ac-a, b);
    calc(a+x, b-x, c);

    x = min(bc-b, c);
    calc(a, b+x, c-x);

    x = min(bc-b, a);
    calc(a-x, b+x, c);

    x = min(cc-c, a);
    calc(a-x, b, c+x);

    x = min(cc-c, b);
    calc(a, b-x, c+x);
}


int main() {
    fin >> ac >> bc >> cc;
    memset(vis, 0, sizeof(vis));
    memset(found, 0, sizeof(found));

    calc(0, 0, cc);

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        fout << res[i];
        if (i < res.size()-1) fout << " ";
    }
    fout << endl;

    return 0;
}
