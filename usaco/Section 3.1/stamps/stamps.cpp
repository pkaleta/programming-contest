/*
ID: piotrek4
LANG: C++
PROG: stamps
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


ifstream fin("stamps.in");
ofstream fout("stamps.out");

const int MAX_N = 55;
const int MAX_K = 205;
const int MAX_V = 10005;


int stamp[MAX_N];
bool vals[MAX_V*MAX_K];

int main() {
    int k, n;
    queue<pair<int, int> > q;

    fin >> k >> n;
    for (int i = 0; i < n; ++i) fin >> stamp[i];

    q.push(make_pair(0, 0));
    vals[0] = true;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int t = p.first;
        int v = p.second;
        if (t == k) break;
        for (int j = 0; j < n; ++j) {
            int nv = v + stamp[j];
            if (!vals[nv]) {
                vals[nv] = true;
                q.push(make_pair(t+1, nv));
            }
        }
    }

    for (int i = 0; i < MAX_V*MAX_K; ++i)
        if (!vals[i]) {
            fout << i-1 << endl;
            break;
        }

    return 0;
}
