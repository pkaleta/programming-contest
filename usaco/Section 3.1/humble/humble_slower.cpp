/*
ID: piotrek4
LANG: C++
PROG: humble
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


ifstream fin("humble.in");
ofstream fout("humble.out");
const int MAX_N = 105;


int main() {
    int n, k, p;
    int primes[MAX_N];
    set<long long> s;
    set<long long>::iterator last;

    fin >> k >> n;
    for (int i = 0; i < k; ++i) {
        fin >> p;
        primes[i] = p;
        s.insert(p);
    }

    long long ret;
    for (int i = 0; i < n; ++i) {
        ret = *s.begin();
        for (int j = 0; j < k; ++j) {
            long long x = ret * primes[j];
            if (s.size() + 1 > n-i+1) {
                last = s.end(); --last;
                if (x > *last)
                    break;
                s.erase(last);
                s.insert(x);
            } else {
                s.insert(x);
            }
        }
        ++s.begin();
        s.erase(s.begin());
    }

    fout << ret << endl;

    return 0;
}
