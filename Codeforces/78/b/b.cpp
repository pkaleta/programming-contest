#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;


vector<pair<int, int> > points;
set<pair<int, int> > m;
int n;

void solve(int l, int r) {
    if (l+1 >= r) return;

    int x = (l+r)/2;

    for(int i = l; i < r; ++i) {
        m.insert(make_pair(points[x].first, points[i].second));
    }

    solve(l, x);
    solve(x+1, r);
}


int main() {
    int xx, yy;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &xx, &yy);
        pair<int, int> p = make_pair(xx, yy);
        points.push_back(p);
        m.insert(p);
    }

    sort(points.begin(), points.end());

    solve(0, n);

    printf("%d\n", (int)m.size());
    for (set<pair<int, int> >::iterator it = m.begin(); it != m.end(); ++it) {
        printf("%d %d\n", it->first, it->second);
    }

    return 0;
}
