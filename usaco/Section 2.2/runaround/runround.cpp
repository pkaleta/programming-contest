/*
ID: piotrek4
LANG: C++
PROG: runround
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
#include <set>
#include <cstring>

using namespace std;


const unsigned long long INF = 1LL << 63LL;
ifstream fin("runround.in");
ofstream fout("runround.out");
int n = 0;
int len;
unsigned long long ret = INF;


unsigned long long getVal(vector<int>& perm) {
    unsigned long long ret = 0;
    for (int i = 0; i < perm.size(); ++i) {
        ret = ret*10+perm[i];
    }
    return ret;
}

bool check(vector<int>& perm) {
    bool vis[20];
    memset(vis, 0, sizeof(vis));
    int i = 0;
    int cnt = 0;
    while (!vis[i] || cnt > perm.size()) {
        vis[i] = true;
        i = (i+perm[i])%perm.size();
        ++cnt;
    }
    return cnt == perm.size() && i == 0;
}

void solve(vector<int>& perm, set<int>& notUsed, int len) {
    if (perm.size() == len) {
        unsigned long long val = getVal(perm);
        if (val > (long long)n && check(perm)) {
            ret = min(ret, val);
        }
        return;
    }
    set<int> notUsed2(notUsed);
    for (set<int>::iterator i = notUsed.begin(); i != notUsed.end(); ++i) {
        if (perm.empty() && *i == 0) continue;
        perm.push_back(*i);
        notUsed2.erase(*i);
        solve(perm, notUsed2, len);
        notUsed2.insert(*i);
        perm.pop_back();
    }
}

int main() {
    string s;
    set<int> notUsed;
    fin >> s;
    len = s.size();

    for (int i = 0; i < s.size(); ++i) {
        n = n*10 + (s[i]-'0');
    }
    for (int i = 1; i <= 9; ++i) {
        notUsed.insert(i);
    }

    vector<int> v;
    solve(v, notUsed, len);
    if (ret == INF) {
        solve(v, notUsed, len+1);
    }

    fout << ret << endl;

    return 0;
}
