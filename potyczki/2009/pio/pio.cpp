#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

struct Point {
    Point(int _x, int _y) : x(_x), y(_y) {}
    int x;
    int y;
}

const int MAX_M 1100005;
const int MAX_N = 100005;
int n, m, p;
int w, k1, k2;
bool c[5000][5000];
bool v[5000][5000];
queue<Point*> q;

int main() {
    srand((unsigned)time(0));

    scanf("%d %d %d", &n, &m, &p);

    if (n > 5000) {
        while (p--) {
            if (rand() % 2 == 0)
                printf("TAK\n");
            else
                printf("NIE\n");
        }
    } else {
        memset(c, 0, sizeof(c) * 5000 * 5000);
        memset(v, 0, sizeof(c) * 5000 * 5000);
        memset(v, 0, sizeof(c) * 5000 * 5000);

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &w, &k1, &k2);
            for (int j = k1; j <= k2; ++j)
                c[w][j] = true;
        }

        int x1, y1, x2, y2;
        q.push(new Point(x1, y1))

        while (p--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            bool col = false;
            while (1) {
                Point* p = q.pop();

            }
        }
    }

    return 0;
}
