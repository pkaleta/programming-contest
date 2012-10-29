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
    int c5, c2;
    c2 = c5 = 0;
    for (int i = 2; i <= n; ++i) {
        int j = i;
        while (j % 2 == 0) {
            ++c2;
            j /= 2;
        }
        while (j % 5 == 0) {
            ++c5;
            j /= 5;
        }
        d = (d*j)%10;
    }
    for (int i = 0; i < c2-c5; ++i)
        d = (d*2)%10;
    fout << d << endl;
    return 0;
}
