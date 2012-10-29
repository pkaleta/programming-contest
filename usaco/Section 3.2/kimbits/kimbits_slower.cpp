/*
ID: piotrek4
LANG: C++
PROG: kimbits
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


ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
long long N, L, I;
map<vector<long long>, long long> dp;

long long countSmaller(long long i, string& s, long long left, bool smaller) {
    if (i == s.size()) {
        if (left == 0) {
            return 1;
        }
        else return 0;
    }

    vector<long long> v(3);
    v[0] = i; v[1] = left; v[2] = smaller;
    if (dp.find(v) != dp.end())
        return dp[v];

    long long ret = 0;
    if (s[i] == '1') {
        if (smaller) {
            ret += countSmaller(i+1, s, left, false);
            if (left > 0) {
                ret += countSmaller(i+1, s, left-1, true);
            }
        } else {
            ret += countSmaller(i+1, s, left, false);
            if (left > 0) {
                ret += countSmaller(i+1, s, left-1, false);
            }
        }
    } else {
        if (smaller) {
            ret += countSmaller(i+1, s, left, true);
        } else {
            ret += countSmaller(i+1, s, left, false);
            if (left > 0) {
                ret += countSmaller(i+1, s, left-1, false);
            }
        }
    }
    dp[v] = ret;
    return ret;
}

string toBinary(long long n) {
    stringstream ss;
    if (n == 0) return "0";
    while (n) {
        ss << abs(n % 2);
        n /= 2;
    }
    string s = ss.str();
    reverse(s.begin(), s.end());
    return s;
}

string binsearch(long long l, long long r, long long x) {
    long long m = (l + r) / 2;
    string s = toBinary(m);
    if (l == r) return s;

    long long cnt = 0;
    dp.clear();
    for (long long i = L+1; i <= N; ++i) {
        string x;
        cnt += countSmaller(0, s, i, true);
    }
//    cout << x << "              " << l << " " << r << " " << m << " " << s << " " << cnt << endl;
    if (x < m-cnt+1) return binsearch(l, m-1, x);
    if (x == m-cnt+1) return binsearch(l, m, x);
    if (x > m-cnt+1) return binsearch(m+1, r, x);
}

long long getMax() {
    long long ret = 0;
    long long left = L;
    for (long long i = 0; i < N; ++i) {
        ret *= 2;
        if (left > 0) {
            ++ret;
            --left;
        }
    }
    return ret;
}

int main() {
    fin >> N >> L >> I;

    string s = binsearch(0, getMax(), I);
    long long size = s.size();
    for (long long i = 0; i < N-size; ++i) s = "0"+s;

    fout << s << endl;
//    s = "10011";
//    string x;
//    cout << countSmaller(0, s, 4, true, x) << endl;
    return 0;
}
