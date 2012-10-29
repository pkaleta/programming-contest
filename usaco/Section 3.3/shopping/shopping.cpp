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
int offer[MAX_S][6];
int offer_price[MAX_S];
int b;
int prods[6];
int p[MAX_CODE];
int dp[6][6][6][6][6][100];
int mapping[1000];


int main() {
    int c, k, n, pp;
    int cur = 1;

    fin >> s;

    for (int a = 0; a <= 5; ++a)
        for (int b = 0; b <= 5; ++b)
            for (int c = 0; c <= 5; ++c)
                for (int d = 0; d <= 5; ++d)
                    for (int e = 0; e <= 5; ++e)
                        for (int i = 0; i <= s; ++i) {
                            dp[a][b][c][d][e][i] = INF;
                        }

    for (int i = 1; i <= s; ++i) {
        fin >> n;
        for (int j = 0; j < n; ++j) {
            fin >> c >> k;
            if (mapping[c] == 0) {
                mapping[c] = cur;
                c = cur++;
            } else {
                c = mapping[c];
            }
            offer[i][c] = k;
        }
        fin >> offer_price[i];
    }
    fin >> b;
    for (int i = 0; i < b; ++i) {
        fin >> c >> k >> pp;
        if (mapping[c] == 0) {
            mapping[c] = cur;
            c = cur++;
        } else {
            c = mapping[c];
        }
        p[c] = pp;
        prods[c] = k;
    }

    dp[prods[1]][prods[2]][prods[3]][prods[4]][prods[5]][0] = 0;

    int a1, b1, c1, d1, e1;
    for (int i = 1; i <= s; ++i)
        for (int a = 0; a <= 5; ++a)
            for (int b = 0; b <= 5; ++b)
                for (int c = 0; c <= 5; ++c)
                    for (int d = 0; d <= 5; ++d)
                        for (int e = 0; e <= 5; ++e) {
                            if (dp[a][b][c][d][e][i-1] < INF) {
//                                cout << i << ": " << a << " " << b << " " << c << " " << d << " " << e << " " << endl;
                                dp[a][b][c][d][e][i] = min(dp[a][b][c][d][e][i], dp[a][b][c][d][e][i-1]);
                                int t = 1;
                                while (1) {
                                    a1 = a-t*offer[i][1];
                                    b1 = b-t*offer[i][2];
                                    c1 = c-t*offer[i][3];
                                    d1 = d-t*offer[i][4];
                                    e1 = e-t*offer[i][5];
//                                    cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << e1 << endl;
                                    if (a1 < 0 || b1 < 0 || c1 < 0 || d1 < 0 || e1 < 0) {
                                        break;
                                    } else {
                                        dp[a1][b1][c1][d1][e1][i] =
                                            min(dp[a1][b1][c1][d1][e1][i], dp[a][b][c][d][e][i-1]+t*offer_price[i]);
                                    }
                                    ++t;
                                }
                            }
                        }

//    for (int i = 1; i <= 5; ++i)
//        cout << i << " " << prods[i] << " " << p[i] << endl;

    int minPrice = INF;
    for (int a = 0; a <= 5; ++a)
        for (int b = 0; b <= 5; ++b)
            for (int c = 0; c <= 5; ++c)
                for (int d = 0; d <= 5; ++d)
                    for (int e = 0; e <= 5; ++e) {
                        if (dp[a][b][c][d][e][s] < INF) {
 //                           cout << a << " " << b << " " << c << " " << d << " " << e << " " << dp[a][b][c][d][e][s] << endl;
                            minPrice = min(minPrice, dp[a][b][c][d][e][s]+a*p[1]+b*p[2]+c*p[3]+d*p[4]+e*p[5]);
                        }
                    }

    fout << minPrice << endl;
    return 0;
}
