/*
ID: piotrek4
LANG: C++
PROG: %s
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


ifstream fin("%s.in");
ofstream fout("%s.out");

const int MAX_N = 1005;
const int MAX_M = 1005;
const int MAX_Q = 100005;
char grid[MAX_N][MAX_M];

int N[MAX_N][MAX_M];
int S[MAX_N][MAX_M];
int E[MAX_N][MAX_M];
int W[MAX_N][MAX_M];
char dir[MAX_Q];
int len[MAX_Q];
vector<char> ret;
int n, m, q;

vector<int> rowbegin[MAX_N];
vector<int> rowend[MAX_N];
vector<int> colbegin[MAX_M];
vector<int> colend[MAX_M];

void findLimits(int y, int x) {
    int yn = lower_bound(colbegin[x].begin(), colbegin[x].end(), y)-colbegin[x].begin();
    if (yn >= colbegin[x].size())
        N[y][x] = colbegin[x][colbegin[x].size()-1];
    else if (colbegin[x][yn] == y)
        N[y][x] = y;
    else
        N[y][x] = colbegin[x][yn-1];

    int ys = lower_bound(colend[x].begin(), colend[x].end(), y)-colend[x].begin();
    if (colend[x][ys] == y)
        S[y][x] = y;
    else
        S[y][x] = colend[x][ys];

    int xe = lower_bound(rowend[y].begin(), rowend[y].end(), x)-rowend[y].begin();
    if (rowend[y][xe] == x)
        E[y][x] = x;
    else
        E[y][x] = rowend[y][xe];

    int xw = lower_bound(rowbegin[y].begin(), rowbegin[y].end(), x)-rowbegin[y].begin();
    if (xw >= rowbegin[y].size())
        W[y][x] = rowbegin[y][rowbegin[y].size()-1];
    else if (rowbegin[y][xw] == x)
        W[y][x] = x;
    else
        W[y][x] = rowbegin[y][xw-1];
}

bool walk(int y, int x) {
    for (int i = 0; i < q; ++i) {
        if (dir[i] == 'N') {
            if (N[y][x] > y-len[i]) return false;
            else y -= len[i];
        } else if (dir[i] == 'S') {
            if (S[y][x] < y+len[i]) return false;
            else y += len[i];
        } else if (dir[i] == 'E') {
            if (E[y][x] < x+len[i]) return false;
            else x += len[i];
        } else if (dir[i] == 'W') {
            if (W[y][x] > x-len[i]) return false;
            else x -= len[i];
        }
    }
    return true;
}


int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }
    scanf("%d\n", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%c %d\n", &dir[i], &len[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m-1; ++j) {
            if (grid[i][j] != '#' && grid[i][j-1] == '#')
                rowbegin[i].push_back(j);
            if (grid[i][j] != '#' && grid[i][j+1] == '#')
                rowend[i].push_back(j);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if (grid[j][i] != '#' && grid[j-1][i] == '#') {
                colbegin[i].push_back(j);
            }
            if (grid[j][i] != '#' && grid[j+1][i] == '#') {
                colend[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '#') {
                findLimits(i, j);
            }
        }
    }

    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                if (walk(i, j)) {
                    ret.push_back(grid[i][j]);
                }
            }
        }
    }

    sort(ret.begin(), ret.end());
    if (ret.size() == 0)
        printf("no solution");
    else {
        for (int i = 0; i < ret.size(); ++i) {
            printf("%c", ret[i]);
        }
    }
    printf("\n");

    return 0;
}
