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
const int MAX_K = 100005;
const long long INF = 1LL << 31LL;

long long primes[MAX_N];
long long prev[MAX_N];
long long hum[MAX_K];

int main() {
    int n, k, p;

    fin >> k >> n;
    for (int i = 0; i < k; ++i) {
        fin >> primes[i];
    }
    hum[0] = 1;

    for (int i = 1; i <= n; ++i) {
        long long min = INF;
        for (int j = 0; j < k; ++j) {
            while (primes[j] * hum[prev[j]] <= hum[i-1]) ++prev[j];

            if (primes[j] * hum[prev[j]] < min)
                min = primes[j] * hum[prev[j]];
        }
        hum[i] = min;
    }

    fout << hum[n] << endl;

    return 0;
}
