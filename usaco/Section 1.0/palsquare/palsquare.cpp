/*
ID: piotrek4
LANG: C++
PROG: palsquare
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

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

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

void print(vector<int> digits) {
    for (int i = 0; i < digits.size(); ++i) {
        if (digits[i] >= 10) {
            fout << (char) (digits[i] + ('A'-10));
        } else {
            fout << digits[i];
        }
    }
}

int main() {
    int b;

    fin >> b;

    for (int n = 1; n <= 300; ++n) {
        vector<int> sqrdig = conv(n*n, b);
        if (isPal(sqrdig)) {
            vector<int> dig = conv(n, b);
            print(dig);
            fout << " ";
            print(sqrdig);
            fout << endl;
        }
    }

    return 0;
}
