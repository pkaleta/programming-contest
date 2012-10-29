#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int base = 20;

string digits[base] = {
    "S",
    ".",
    "..",
    "...",
    "....",
    "-",
    ". -",
    ".. -",
    "... -",
    ".... -",
    "- -",
    ". - -",
    ".. - -",
    "... - -",
    ".... - -",
    "- - -",
    ". - - -",
    ".. - - -",
    "... - - -",
    ".... - - -"
};

int main() {
    int n;
    string d;
    vector<long long> number;

    while (scanf("%d\n", &n) && n) {
        number.clear();
        for (int i = 0; i < n; ++i) {
            char tmp[base];
            cin.getline(tmp, base);
            d = string(tmp);
            for (int j = 0; j < base; ++j) {
                if (d == digits[j]) {
                    number.push_back(j);
                }
            }
        }
        long long mul = 1;
        long long result = number[number.size()-1];
        for (int i = number.size()-2; i >= 0; --i) {
            if (i == number.size()-3) {
                mul = 360;
            } else {
                mul *= 20;
            }
            result += mul*number[i];
        }
        printf("%lld\n", result);
        n = 0;
    }
    return 0;
}
