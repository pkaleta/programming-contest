/*
ID: piotrek4
LANG: C++
PROG: fact4
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


ifstream fin("fact4.in");
ofstream fout("fact4.out");


int main() {
    int n;

    fin >> n;

    int d = 1;
    for (int i = 1; i <= n; ++i) {
        d *= i;
        while (d % 10 == 0) d /= 10;
        d %= 100000;
    }
    fout << d % 10 << endl;
    return 0;
}
