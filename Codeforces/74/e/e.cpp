#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;


const int MAX_SIZE = 5005;

char grid[MAX_SIZE][MAX_SIZE];
int n, m;
bool taken[MAX_SIZE][MAX_SIZE];
bool vis[MAX_SIZE][MAX_SIZE];

pair<int, int> findNext(int sy, int sx) {
    pair<int, int> ret = make_pair(-1, -1);
    int x;
    int y;

    if (grid[sy][sx] == 'U') {
        x = sx;
        y = sy-1;
        while (y >= 0 && y < n && x >= 0 && x < m) {
            if (!taken[y][x] && grid[y][x] != '.') {
                ret.first = y;
                ret.second = x;
                return ret;
            }
            --y;
        }
        return ret;
    }

    if (grid[sy][sx] == 'D') {
        x = sx;
        y = sy+1;
        while (y >= 0 && y < n && x >= 0 && x < m) {
            if (!taken[y][x] && grid[y][x] != '.') {
                ret.first = y;
                ret.second = x;
                return ret;
            }
            ++y;
        }
        return ret;
    }

    if (grid[sy][sx] == 'L') {
        x = sx-1;
        y = sy;
        while (y >= 0 && y < n && x >= 0 && x < m) {
            if (!taken[y][x] && grid[y][x] != '.') {
                ret.first = y;
                ret.second = x;
                return ret;
            }
            --x;
        }
        return ret;
    }

    if (grid[sy][sx] == 'R') {
        x = sx+1;
        y = sy;
        while (y >= 0 && y < n && x >= 0 && x < m) {
            if (!taken[y][x] && grid[y][x] != '.') {
                ret.first = y;
                ret.second = x;
                return ret;
            }
            ++x;
        }
        return ret;
    }
}

vector<pair<int, int> > findStarts() {
    vector<pair<int, int> > starts;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            bool flag = false;

            if (grid[i][j] != '.') {
                for (int k = j+1; k < m && !flag; ++k) {
                    if (grid[i][k] == 'L') {
                        flag = true;
                        break;
                    }
                }

                for (int k = j-1; k >= 0 && !flag; --k) {
                    if (grid[i][k] == 'R') {
                        flag = true;
                        break;
                    }
                }

                for (int k = i+1; k < n && !flag; ++k) {
                    if (grid[k][j] == 'U') {
                        flag = true;
                        break;
                    }
                }

                for (int k = i-1; k >= 0 && !flag; --k) {
                    if (grid[k][j] == 'D') {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    starts.push_back(make_pair(i, j));
                }
            }
        }
    }
    return starts;
}

int visit(int y, int x) {
    int ret = 0;

    while (y != -1 && x != -1) {
//        cout << x << ", " << y << endl;
        ++ret;
        vis[y][x] = true;
        taken[y][x] = true;
        pair<int, int> p = findNext(y, x);
        y = p.first;
        x = p.second;
    }
//        cout << x << ", " << y << endl;

    return ret;
}

int main() {
    scanf("%d%d\n", &n, &m);
    string line;
    char c;

    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = line[j];
        }
        scanf("%c", &c);
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << grid[i][j];
//        }
//        cout << endl;
//    }

    vector<pair<int, int> > starts = findStarts();
    map<int, int> count;


    int mx = -1;
    int ret;

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < starts.size(); ++i) {
        memset(taken, 0, sizeof(taken));
        int y = starts[i].first;
        int x = starts[i].second;
        ret = visit(y, x);

        if (count.find(ret) != count.end()) {
            count[ret]++;
        } else {
            count[ret] = 1;
        }

//        cout << x << ", " << y << ": " << ret << endl;

        if (ret > mx) {
            mx = ret;
        }
    }

    starts.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] != '.') {
                starts.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < starts.size(); ++i) {
        memset(taken, 0, sizeof(taken));
        int y = starts[i].first;
        int x = starts[i].second;
        ret = visit(y, x);

        if (count.find(ret) != count.end()) {
            count[ret]++;
        } else {
            count[ret] = 1;
        }

        if (ret > mx) {
            mx = ret;
        }
    }

    printf("%d %d\n", mx, count[mx]);

    return 0;
}
