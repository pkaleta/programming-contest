/*
ID: piotrek4
LANG: C++
PROG: rect1
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


ifstream fin("rect1.in");
ofstream fout("rect1.out");

const int MAX_RECT = 1005;
const int MAX_COL = 2500;

int a, b, n;
int llx[MAX_RECT], lly[MAX_RECT], urx[MAX_RECT], ury[MAX_RECT], c[MAX_RECT];
vector<pair<int, int> > xs;
set<pair<int, int> > ys;
set<int, greater<int> > rect;
int area[MAX_COL];
map<int, int> height;


int main() {
    fin >> a >> b >> n;

    llx[1] = 0; lly[1] = 0;
    urx[1] = a; ury[1] = b;
    c[1] = 1;
    xs.push_back(make_pair(llx[1], 1));
    xs.push_back(make_pair(urx[1], -1));

    for (int i = 2; i <= n+1; ++i) {
        fin >> llx[i] >> lly[i] >> urx[i] >> ury[i] >> c[i];
        xs.push_back(make_pair(llx[i], i));
        xs.push_back(make_pair(urx[i], -i));
    }
    sort(xs.begin(), xs.end());

    for (int i = 0; i < xs.size(); ++i) {
        int num = xs[i].second;
//        cout << "************* " << num << endl;

        for (map<int, int>::iterator it = height.begin(); it != height.end(); ++it) {
            int num = it->first;
            int h = it->second;
            area[c[num]] += h*(xs[i].first - xs[i-1].first);
//            cout << num << ": " << h << " " << area[c[num]] << endl;
        }
        height.clear();

        if (num > 0) { // poczatek
            ys.insert(make_pair(lly[num], num));
            ys.insert(make_pair(ury[num], -num));
        } else { // koniec
            ys.erase(make_pair(lly[-num], -num));
            ys.erase(make_pair(ury[-num], num));
        }

        if (ys.size() > 0) {
            rect.clear();
            set<pair<int, int> >::iterator it = ys.begin();
//            cout << "#### " << it->first << " " << it->second << endl;
            num = it->second;
            int prevy = it->first;
            rect.insert(num);
            height[num] = 0;
            ++it;
            for (; it != ys.end(); ++it) {
                pair<int, int> p = *it;
                int y = it->first;
                int num = it->second;

                int topnum = *rect.begin();
//                cout << "#### " << topnum << " " << prevy << " " << it->first << " " << it->second << endl;
                height[topnum] += y - prevy;
                prevy = y;

                if (num > 0) { // poczatek
                    rect.insert(num);
                    height[num] = 0;
                } else { // koniec
                    rect.erase(-num);
                }
            }
        }
    }

    for (int i = 1; i <= MAX_COL; ++i) {
        if (area[i] > 0) {
            fout << i << " " << area[i] << endl;
        }
    }
    return 0;
}
