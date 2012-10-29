#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_COLORS = 10;
const int MAX_R = 105;
const int MAX_C= 105;

int r;
int c;
int sx;
int sy;
int ex;
int ey;

struct Field {
    int x;
    int y;
    int dist;

    Field(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

vector<pair<int, int> > colors[256];
queue<Field*> q;

char maze[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];
int distance;

void maybeAdd(int x, int y, int dist) {
    if (x >= 0 && x < c && y >= 0 && y < r && !visited[y][x] && maze[y][x] != 'W') {
        visited[y][x] = true;
        q.push(new Field(x, y, dist));
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        scanf("%d %d ", &r, &c);

        for (int i = 0; i < 256; ++i) {
            colors[i].clear();
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char c;
                scanf("%c", &c);
                maze[i][j] = c;
                if (c == 'S') {
                    sx = j;
                    sy = i;
                }
                if (c >= '1' && c <= '9') {
                    colors[c].push_back(make_pair(i, j));
                }
            }
            scanf("\n");
        }

//        for (int i = 0; i < r; ++i) {
//            for (int j = 0; j < c; ++j) {
//                printf("%c ", maze[i][j]);
//            }
//            printf("\n");
//        }

        while (!q.empty()) {
            q.pop();
        }
        memset(visited, 0, sizeof(visited));

        q.push(new Field(sx, sy, 0));
        while (!q.empty()) {
            Field* f = q.front();
            q.pop();
            int x = f->x;
            int y = f->y;
            int dist = f->dist;
//            visited[y][x] = true;

            if (maze[y][x] == 'E') {
                printf("%d\n", dist);
                break;
            }
            if (maze[y][x] >= '1' && maze[y][x] <= '9') {
                vector<pair<int, int> > tmp = colors[maze[y][x]];

                for (int i = 0; i < tmp.size(); ++i) {
                    maybeAdd(tmp[i].second, tmp[i].first, dist+1);
                }
            }
            maybeAdd(x+1, y, dist+1);
            maybeAdd(x, y+1, dist+1);
            maybeAdd(x-1, y, dist+1);
            maybeAdd(x, y-1, dist+1);
        }
    }
    return 0;
}

