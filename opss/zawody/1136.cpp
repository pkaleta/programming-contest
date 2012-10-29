#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V = 'z' + 1;

int t[MAX_V][MAX_V];
vector<int> clens[MAX_V];
bool vis[MAX_V];
int mind[MAX_V];

void find_cycles(char v, int d) {
    mind[v] = d;
//    printf("jestem w %c odleglosc: %d\n", v, d);
    vis[v] = true;
    for (char c = 'A'; c <= 'z'; ++c) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            if (t[v][c]) {
                if (vis[c]) {
                    if (d > mind[c]) {
//                        printf("krawedz %c -> %c i znalazlem cykl o dlugosci %d %d\n", v, c, d, mind[c]);
                        clens[c].push_back(d - mind[c] + 1);
                    } else if (c == v) {
                        clens[c].push_back(0);
                    }
                }
                else {
//                    printf("dorzucam: %c, depth: %d\n", c, d + 1);
                    find_cycles(c, d + 1);
                }
            }
        }
    }
}

int result;
int paths[MAX_V][55];

void bfs(char start, char end) {
    for (int i = 0; i < MAX_V; ++i)
        for (int j = 0; j < 55; ++j)
            paths[i][j] = 0;
    queue<pair<pair<char, char>, int>* > q;
    while (!q.empty()) {
        pair<int, int> v = q.pop();
        if (v.first == end) {
            result += current_value;
        } else {
            for (char i = 'A'; i <= 'z'; ++i) {
                if (i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z') {
                    if (t[v][i]) {
                        dfs(c, d + 1, current_value + t[v][i]);
                    }
                }
            }
        }
    }
}

int main() {
    int c;
    result = 0;

    scanf("%d\n", &c);
    while (c--) {
        char a, b;
        scanf("%c %c\n", &a, &b);
        ++t[a][b];
    }
    for (char c = 'A'; c <= 'z'; ++c) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            vis[c] = false;
            mind[c] = 0;
        }
    }
    for (char c = 'A'; c <= 'z'; ++c) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            if (!vis[c]) {
//                printf("********************\n");
                find_cycles(c, 0);
            }
        }
    }

    int d;
    int a, b;
    char x, y;

    scanf("%d", &d);
    while (d--) {
        scanf("%d %d %c %c", &a, &b, &x, &y);
//        for (char i = 'A'; i <= 'z'; ++i) {
//            if (i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z') {
//                for (char j = 'A'; j <= 'z'; ++j) {
//                    if (j >= 'A' && j <= 'Z' || j >= 'a' && j <= 'z') {
//                        for (char k = 'A'; k <= 'z'; ++k) {
//                            if (k >= 'A' && k <= 'Z' || k >= 'a' && k <= 'z') {
//                                if (k != i && k != j) {
//                                    int tmp = t[i][k] * t[k][j];
//                                    paths[i][j][tmp]++;
//                                    for (int x = 0; x < clens[k].size(); ++x) {
//                                        int z = 0;
//                                        while (z * ) {
//
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
    }
    return 0;
}
