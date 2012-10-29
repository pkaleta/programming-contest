/*
ID: piotrek4
LANG: C++
PROG: msquare
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

const int INF = 1 << 26;
const int SIZE = 8;

ifstream fin("msquare.in");
ofstream fout("msquare.out");
vector<int> final(SIZE);
string ret;
set<vector<int> > visited;

bool cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < SIZE; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

vector<int> transformA(vector<int> a) {
    vector<int> ret(SIZE);
    for (int i = 0; i < 4; ++i) {
        ret[i] = a[7-i];
        ret[7-i] = a[i];
    }
    return ret;
}

vector<int> transformB(vector<int> a) {
    vector<int> ret(SIZE);
    for (int i = 0; i < 4; ++i) {
        ret[(i+1)%4] = a[i];
        if (i == 3)
            ret[7] = a[4];
        else
            ret[6-i] = a[7-i];
    }
    return ret;
}

vector<int> transformC(vector<int> a) {
    vector<int> ret(SIZE);
    for (int i = 0; i < SIZE; ++i)
        ret[i] = a[i];
    ret[2] = a[1];
    ret[1] = a[6];
    ret[6] = a[5];
    ret[5] = a[2];
    return ret;
}

string bfs(vector<int> cur) {
    queue<pair<vector<int>, string> > q;
    string s;
    q.push(make_pair(cur, ""));

    while (!q.empty()) {
        pair<vector<int>, string> p = q.front();
        q.pop();
        cur = p.first;
        s = p.second;

//        for (int i = 0; i < SIZE; ++i)
//            cout << cur[i] << " ";
//        cout << endl;



        if (visited.find(cur) != visited.end()) continue;
        visited.insert(cur);

        if (cmp(cur, final))
            return s;

        vector<int> a = transformA(cur);
        if (visited.find(a) == visited.end()) q.push(make_pair(a, s + "A"));
        vector<int> b = transformB(cur);
        if (visited.find(b) == visited.end()) q.push(make_pair(b, s + "B"));
        vector<int> c = transformC(cur);
        if (visited.find(c) == visited.end()) q.push(make_pair(c, s + "C"));
    }
}


int main() {
    vector<int> init(SIZE);

    for (int i = 0; i < SIZE; ++i) {
        fin >> final[i];
        init[i] = i+1;
    }

    string ret = bfs(init);

    fout << ret.size() << endl << ret << endl;

    return 0;
}
