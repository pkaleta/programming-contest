#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1000005;
const int MAX_M = 1000005;

struct Edge {
    int a, b, id;
    bool operator<(const Edge&) const;
    //Edge& operator=(const Edge&);
} edges[MAX_M];

bool Edge::operator< (const Edge& edge) const {
    return (this->a < edge.a) || (this->a == edge.a && this->b > edge.b);
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    if (m > n)
        m = n;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if (a < b) {
            edges[i].a = a;
            edges[i].b = b;
        }
        else {
            edges[i].a = b;
            edges[i].b = a;
        }
        edges[i].id = i + 1;
    }
    sort(edges, edges + m);
    Edge* stack[MAX_M];
    int h = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        while (h > 0 && stack[h - 1]->b == i)
            --h;
        while (j < m && edges[j].a == i) {
            if (h > 0 && edges[j].b > stack[h - 1]->b) {
                printf("%d %d\n", stack[h - 1]->id, edges[j].id);
                return 0;
            }
            stack[h++] = &edges[j];
            ++j;
        }
    }
    printf("NIE\n");
    return 0;
}
