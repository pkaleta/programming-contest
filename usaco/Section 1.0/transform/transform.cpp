/*
ID: piotrek4
LANG: C++
PROG: transform
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool cmp(int n, vector<string>& a, vector<string>& b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

bool rot90(int n, vector<string>& src, vector<string>& dest) {
    vector<string> tmp(src);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = src[n-j-1][i];
        }
    }
    return cmp(n, tmp, dest);
}

bool rot180(int n, vector<string>& src, vector<string>& dest) {
    vector<string> tmp(src);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = src[n-i-1][n-j-1];
        }
    }
    return cmp(n, tmp, dest);
}

bool rot270(int n, vector<string>& src, vector<string>& dest) {
    vector<string> tmp(src);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = src[j][n-i-1];
        }
    }
    return cmp(n, tmp, dest);
}

bool reflect(int n, vector<string>& src, vector<string>& dest) {
    vector<string> tmp(src);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = src[i][n-j-1];
        }
    }

    return cmp(n, tmp, dest);
}

bool id(int n, vector<string>& src, vector<string>& dest) {
    return cmp(n, src, dest);
}

bool (*tran[7])(int, vector<string>&, vector<string>&) = {NULL};

bool combine(int n, vector<string>& src, vector<string>& dest) {
    vector<string> tmp(src);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = src[i][n-j-1];
        }
    }

    bool ret = false;
    for (int t = 1; t <= 3; ++t) {
        vector<string> x = tmp;
        ret = ret || tran[t](n, x, dest);
    }

    return ret;
}


int main() {
    int n;
    string s;
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    vector<string> src;
    vector<string> dest;
    tran[1] = &rot90;
    tran[2] = &rot180;
    tran[3] = &rot270;
    tran[4] = &reflect;
    tran[5] = &combine;
    tran[6] = &id;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> s;
        src.push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        fin >> s;
        dest.push_back(s);
    }

    for (int i = 1; i <= 6; ++i) {
        if (tran[i](n, src, dest)) {
            fout << i << endl;
            return 0;
        }
    }

    fout << 7 << endl;
    return 0;
}
