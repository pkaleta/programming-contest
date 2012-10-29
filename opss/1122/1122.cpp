#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
char t[MAX_N][MAX_N];
bool v[MAX_N][MAX_N];
int n;
int kx, ky;
int sx, sy;
int depth;

void dfs(int x, int y) {
    v[x][y] = true;
    if (x == 0 && y == n-1)
        return;
    if (x - 1 >= 0 && !v[x - 1][y]) {
        if (t[x - 1][y] == 'p')
            dfs(x - 1, y);
        else if (t[x - 1][y] == '.') {
            t[x - 1][y] = 'p';
            dfs(x - 1, y);
        }
    }
    if (x + 1 < n && !v[x + 1][y]) {
        if (t[x + 1][y] == 'l')
            dfs(x + 1, y);
        else if (t[x + 1][y] == '.') {
            t[x + 1][y] = 'l';
            dfs(x + 1, y);
        }
    }
    if (y - 1 >= 0 && !v[x][y - 1]) {
        if (t[x][y - 1] == 'd')
            dfs(x, y - 1);
        else if (t[x][y - 1] == '.') {
            t[x][y - 1] = 'd';
            dfs(x, y - 1);
        }
    }
    if (y + 1 < n && !v[x][y + 1]) {
        if (t[x][y + 1] == 'g')
            dfs(x, y + 1);
        else if (t[x][y + 1] == '.') {
            t[x][y + 1] = 'g';
            dfs(x, y + 1);
        }
    }
}

void dfs2(int x, int y, bool flag) {
    if (flag)
        printf("%d %d\n", x + 1, n - y);
    else
        ++depth;
    if (x == kx && y == ky)
        return;
    if (t[x][y] == 'p')
        dfs2(x + 1, y, flag);
    else if (t[x][y] == 'l')
        dfs2(x - 1, y, flag);
    else if (t[x][y] == 'g')
        dfs2(x, y - 1, flag);
    else if (t[x][y] == 'd')
        dfs2(x, y + 1, flag);

}

int main() {
    int c;
    sx = sy = 0;

    scanf("%d\n", &c);
    while (c--) {
        scanf("%d\n", &n);
        memset(v, 0, sizeof(bool) * MAX_N * MAX_N);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%c", &t[j][i]);
                if (t[j][i] == 'k') {
                    kx = j;
                    ky = i;
                }
            }
            scanf("\n");
        }
        dfs(kx, ky);
        depth = 0;
        dfs2(0, n - 1, false);
        printf("%d\n", depth);
        dfs2(0, n - 1, true);
    }
    return 0;
}
