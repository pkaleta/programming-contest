#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

class Point {
    public:
        long long x;
        long long y;

        Point() {}

        Point(long long x, long long y) {
            this->x = x;
            this->y = y;
        }

        bool operator == (Point& p) {
            return this->x == p.x && this->y == p.y;
        }
};

int ccw(Point p0, Point p1, Point p2)
{
    long long dx1, dx2, dy1, dy2;

    dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

    if (dx1*dy2 > dy1*dx2)
        return 1;
    if (dx1*dy2 < dy1*dx2)
        return -1;
    if ((dx1*dx2 < 0) || (dy1*dy2 < 0))
        return -1;
    if ((dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2))
        return 1;
    return 0;
}

const int MAXK = 1005;

bool border(Point a, Point b, Point c) {
    int c1 = ccw(a, b, c);
    if (c1 == 0) {
        return true;
    }
    return false;
}

bool crosses(Point a, Point b, Point c, Point d) {
    int c1 = ccw(a, b, c);
    int c2 = ccw(a, b, d);
    int c3 = ccw(c, d, a);
    int c4 = ccw(c, d, b);
    return c1 * c2 <= 0 && c3 * c4 <= 0;
}

int main() {
    int d, k;
    Point s;
    Point ps[MAXK];
    Point p;

    scanf("%d", &d);
    while (d--) {
        scanf("%lld%lld", &s.x, &s.y);
        p.x = s.x;
        p.y = 0;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &ps[i].x, &ps[i].y);
            if (ps[i].y > p.y) {
                p.y = ps[i].y;
            }
        }
        ps[k].x = ps[0].x;
        ps[k].y = ps[0].y;
        ++k;
        ++p.y;
        int cs = 0;
        bool flag = false;
        int count = 0;
        for (int i = 1; i < k; ++i) {
            if (border(ps[i-1], ps[i], s)) {
                flag = true;
                break;
            }
            if (crosses(ps[i-1], ps[i], s, p)) {
                if (ccw(s, p, ps[i]) == 0 &&  ccw(s, p, ps[i-1]) == 0) {
                    cs += 2;
                } else if (ps[i-1].x == s.x && ps[i-1].y > s.y) {
                    Point x;
                    if (i-2 < 0) {
                        x = ps[k+(i-2)];
                    } else {
                        x = ps[i-2];
                    }
                    if (ccw(s, p, ps[i]) * ccw(s, p, x) > 0) {
                        count -= 2;
                    }
                    ++count;
                }
                if (ps[i].x == s.x && ps[i].y > s.y) {
                    ++count;
                }
                ++cs;
            }
        }
//        printf("********** cs: %d, count: %d\n", cs, count);
        cs -= count / 2;

        if (cs & 1 || flag) {
            printf("TAK\n");
        } else {
            printf("NIE\n");
        }
    }
    return 0;
}


