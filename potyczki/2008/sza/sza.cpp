#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 200005;

struct Figure {
    char type;
    int x;
    int y;
    int pos_x, pos_y, pos_lr, pos_rl;
} figures[MAX_N];

Figure* sorted_x[MAX_N];
Figure* sorted_y[MAX_N];
Figure* sorted_lr[MAX_N];
Figure* sorted_rl[MAX_N];
int n, m, x, y;
char f;
map<int, vector<int> > M;

struct OrderX {
    bool operator() (const Figure* f1, const Figure* f2) const {
        return (f1->x < f2->x || (f1->x == f2->x && f1->y < f2->y));
    }
} order_x;

struct OrderY {
    bool operator() (const Figure* f1, const Figure* f2) const {
        return (f1->y < f2->y || (f1->y == f2->y && f1->x < f2->x));
    }
} order_y;

struct OrderSum {
    bool operator() (const Figure* f1, const Figure* f2) const {
        int sum1 = f1->x + f1->y;
        int diff1 = f1->x - f1->y;
        int sum2 = f2->x + f2->y;
        int diff2 = f2->x - f2->y;
        return (sum1 < sum2 || (sum1 == sum2 && diff1 < diff2));
    }
} order_sum;

struct OrderDiff {
    bool operator() (const Figure* f1, const Figure* f2) const {
        int sum1 = f1->x + f1->y;
        int diff1 = f1->x - f1->y;
        int sum2 = f2->x + f2->y;
        int diff2 = f2->x - f2->y;
        return (diff1 < diff2 || (diff1 == diff2 && sum1 < sum2));
    }
} order_diff;

long long vertical(int i) {
    int tmp = figures[i].pos_x;
    long long sum = 0;
    if (tmp < n - 1 && sorted_x[tmp + 1]->x == sorted_x[tmp]->x)
        sum += sorted_x[tmp + 1]->y - sorted_x[tmp]->y - 1;
    else
        sum += m - figures[i].y;

    if (tmp > 0 && sorted_x[tmp - 1]->x == sorted_x[tmp]->x)
        sum += sorted_x[tmp]->y - sorted_x[tmp - 1]->y - 1;
    else
        sum += figures[i].y - 1;
    return sum;
}

long long horizontal(int i) {
    int tmp = figures[i].pos_y;
    long long sum = 0;
    if (tmp < n - 1 && sorted_y[tmp + 1]->y == sorted_y[tmp]->y)
        sum += sorted_y[tmp + 1]->x - sorted_y[tmp]->x - 1;
    else
        sum += m - figures[i].x;

    if (tmp > 0 && sorted_y[tmp - 1]->y == sorted_y[tmp]->y)
        sum += sorted_y[tmp]->x - sorted_y[tmp - 1]->x - 1;
    else
        sum += figures[i].x - 1;
    return sum;
}

inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long leftright(int i) {
    int tmp = figures[i].pos_lr;
    long long sum = 0;
    long long tmp_diff = sorted_lr[tmp]->x - sorted_lr[tmp]->y;
    if (tmp < n - 1 && (tmp_diff == sorted_lr[tmp + 1]->x - sorted_lr[tmp + 1]->y))
        sum += sorted_lr[tmp + 1]->x - sorted_lr[tmp]->x - 1;
    else
        sum += min(m - figures[i].x, m - figures[i].y);

    if (tmp > 0 && (tmp_diff == sorted_lr[tmp - 1]->x - sorted_lr[tmp - 1]->y))
        sum += sorted_lr[tmp]->x - sorted_lr[tmp - 1]->x - 1;
    else
        sum += min(figures[i].x - 1, figures[i].y - 1);
    return sum;
}

long long rightleft(int i) {
    int tmp = figures[i].pos_rl, sum = 0;
    long long tmp_sum = sorted_rl[tmp]->x + sorted_rl[tmp]->y;
    if (tmp < n - 1 && (tmp_sum == sorted_rl[tmp + 1]->x + sorted_rl[tmp + 1]->y))
        sum += sorted_rl[tmp + 1]->x - sorted_rl[tmp]->x - 1;
    else
        sum += min(m - figures[i].x, figures[i].y - 1);

    if (tmp > 0 && (tmp_sum == sorted_rl[tmp - 1]->x + sorted_rl[tmp - 1]->y))
        sum += sorted_rl[tmp]->x - sorted_rl[tmp - 1]->x - 1;
    else
        sum += min(figures[i].x - 1, m - figures[i].y);
    return sum;
}

bool is_free(int x, int y) {
    if (x < 1 || x > m || y < 1 || y > m)
        return false;
    return M.find(x) == M.end() ||
           lower_bound(M[x].begin(), M[x].end(), y) == M[x].end() ||
           *lower_bound(M[x].begin(), M[x].end(), y) != y;
}

int main() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%c %d %d\n", &figures[i].type, &figures[i].x, &figures[i].y);
        sorted_x[i] = sorted_y[i] = sorted_lr[i] = sorted_rl[i] = &figures[i];
        M[figures[i].x].push_back(figures[i].y);
    }
    sort(sorted_x, sorted_x + n, order_x);
    sort(sorted_y, sorted_y + n, order_y);
    sort(sorted_rl, sorted_rl + n, order_sum);
    sort(sorted_lr, sorted_lr + n, order_diff);
    map<int, vector<int> >::iterator it;
    for (it = M.begin(); it != M.end(); ++it)
        sort(it->second.begin(), it->second.end());
    for (int i = 0; i < n; ++i)
        sorted_x[i]->pos_x = sorted_y[i]->pos_y = sorted_lr[i]->pos_lr = sorted_rl[i]->pos_rl = i;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        switch(figures[i].type) {
            case 'G':
                printf("%lld\n", rightleft(i) + leftright(i));
                break;
            case 'H':
                printf("%lld\n", horizontal(i) + vertical(i) + leftright(i) + rightleft(i));
                break;
            case 'K': {
                    int sum = 0;
                    for (int k = -1; k <= 1; ++k)
                        for (int l = -1; l <= 1; ++l)
                            if (k != 0 || l != 0)
                                sum += is_free(figures[i].x + k, figures[i].y + l);
                    printf("%d\n", sum);
                    break;
                }
            case 'S': {
                    Figure& f = figures[i];
                    printf("%d\n", is_free(f.x - 2, f.y - 1) +
                                   is_free(f.x - 1, f.y - 2) +
                                   is_free(f.x + 1, f.y - 2) +
                                   is_free(f.x + 2, f.y - 1) +
                                   is_free(f.x + 2, f.y + 1) +
                                   is_free(f.x + 1, f.y + 2) +
                                   is_free(f.x - 1, f.y + 2) +
                                   is_free(f.x - 2, f.y + 1));
                    break;
                }
            case 'W':
                printf("%lld\n", horizontal(i) + vertical(i));
                break;
        }
    }
    return 0;
}
