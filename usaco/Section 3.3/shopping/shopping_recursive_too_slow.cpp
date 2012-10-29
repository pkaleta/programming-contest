/*
ID: piotrek4
LANG: C++
PROG: shopping
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

const int MAX_S = 105;
const int MAX_B = 10;
const int MAX_CODE = 1005;

const int INF = 1 << 26;

ifstream fin("shopping.in");
ofstream fout("shopping.out");
int s;
vector<pair<int, int> > offer[MAX_S];
int offer_price[MAX_S];
int b;
map<int, int> prods;
int p[MAX_CODE];
int minPrice;
map<map<int, int>, int> dp;


int calc(map<int, int>& prods) {
    if (prods.empty()) return 0;

    if (dp.find(prods) != dp.end())
        return dp[prods];

    int ret = 0;
    for (map<int, int>::iterator it = prods.begin(); it != prods.end(); ++it) {
        ret += it->second*p[it->first];
    }

    for (int i = 0; i < s; ++i) {
        map<int, int> prods2(prods);
        bool check = true;
        for (int j = 0; j < offer[i].size(); ++j) {
            pair<int, int> p = offer[i][j];
            int c = p.first;
            int k = p.second;
            if (prods2[c] < k) {
                check = false;
                break;
            }
            prods2[c] -= k;
            if (prods2[c] == 0) prods2.erase(c);
        }
        if (check)
            ret = min(ret, offer_price[i] + calc(prods2));
    }

    dp[prods] = ret;
    return ret;
}

int main() {
    int c, k, n, pp;

    fin >> s;
    for (int i = 0; i < s; ++i) {
        fin >> n;
        for (int j = 0; j < n; ++j) {
            fin >> c >> k;
            offer[i].push_back(make_pair(c, k));
        }
        fin >> offer_price[i];
    }
    fin >> b;
    for (int i = 0; i < b; ++i) {
        fin >> c >> k >> pp;
        p[c] = pp;
        prods[c] = k;
    }

    minPrice = calc(prods);

    fout << minPrice << endl;
    return 0;
}
