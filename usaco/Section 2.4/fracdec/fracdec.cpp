/*
ID: piotrek4
LANG: C++
PROG: fracdec
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


ifstream fin("fracdec.in");
ofstream fout("fracdec.out");


const int MAX_N = 1000000;
int mem[MAX_N];

int main() {
    int n, d;

    fin >> n >> d;

    stringstream ss;
    ss << n / d << ".";
    n = (n % d)*10;

    int i = ss.str().size();
    string ret;
    while (1) {
        if (n == 0) {
            ret = ss.str();
            break;
        }
        if (mem[n]) {
            ret = ss.str();
            ret.insert(mem[n], "(");
            ret += ")";
            break;
        }
        mem[n] = i;
        ss << n / d;
        n = (n % d)*10;
        ++i;
    }
    if (ret[ret.size()-1] == '.') ret += "0";

    for (int i = 0; i < ret.size(); i += 76) {
        fout << ret.substr(i, 76) << endl;
    }
    return 0;
}
