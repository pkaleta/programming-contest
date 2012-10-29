/*
ID: piotrek4
LANG: C++
PROG: dualpal
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

vector<int> conv(int n, int b) {
    vector<int> digits;

    while (n > 0) {
        digits.push_back(n % b);
        n /= b;
    }

    int halfSize = digits.size() / 2;
    for (int i = 0; i < halfSize; ++i) {
        int d = digits[i];
        digits[i] = digits[digits.size()-i-1];
        digits[digits.size()-i-1] = d;
    }
    return digits;
}

bool isPal(vector<int> digits) {
    for (int i = 0; i < digits.size(); ++i) {
        if (digits[i] != digits[digits.size()-i-1])
            return false;
    }
    return true;
}

int main() {
    int n, s;

    fin >> n >> s;

    int num = s;
    for (int i = 0; i < n; ++i) {
        ++num;
        while (true) {
            int bases = 0;
            for (int b = 2; b <= 10; ++b) {
                vector<int> ds = conv(num, b);
                if (isPal(ds)) {
                    ++bases;
                    if (bases >= 2)
                        break;
                }
            }
            if (bases >= 2)
                break;
            ++num;
        }
        fout << num << endl;
    }

    return 0;
}
