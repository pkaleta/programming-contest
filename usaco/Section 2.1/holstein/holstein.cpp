/*
ID: piotrek4
LANG: C++
PROG: holstein
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


const int MAX_VIT = 30;
const int MAX_FEED = 20;
const int INF = 100;


ifstream fin("holstein.in");
ofstream fout("holstein.out");
int a[MAX_VIT], v, b[MAX_FEED][MAX_VIT], g;


bool check(int* x) {
    for (int i = 0; i < v; ++i) {
        if (x[i] < a[i]) return false;
    }
    return true;
}


int main() {
    int minTypes = INF;
    vector<int> result;

    fin >> v;
    for (int i = 0; i < v; ++i) {
        fin >> a[i];
    }

    fin >> g;
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < v; ++j) {
            fin >> b[i][j];
        }
    }

    for (int n = 0; n < (1<<g); ++n) {
        int types = 0;
        int val = n;
        int tmp[MAX_VIT];
        memset(tmp, 0, sizeof(tmp));
        int i = 0;
        vector<int> feed;
        while (val) {
            if (val & 1) {
                feed.push_back(i);
                for (int j = 0; j < v; ++j) {
//                    cout << b[i][j] << " ";
                    tmp[j] += b[i][j];
                }
//                cout << endl << "*************" << endl;
                ++types;
            }
            ++i;
            val >>= 1;
        }


//        cout << "********** " << n << endl;
//        for (int i = 0; i < feed.size(); ++i) {
//            cout << feed[i]+1 << endl;
//        }
//        for (int i = 0; i < v; ++i) {
//            cout << tmp[i] << " ";
//        }
//        cout << endl << endl;

        if (check(tmp)) {
            if (result.size() == 0 || feed.size() < result.size()) {
                result = feed;
            }
        }
    }
    sort(result.begin(), result.end());
    fout << result.size();
    for (int i = 0; i < result.size(); ++i) {
        fout << " " << result[i]+1;
    }
    fout << endl;
    return 0;
}
