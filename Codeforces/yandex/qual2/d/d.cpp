#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 5005;

int n;

class Edge {
    public:
        int v;
        int c;

        Edge(int v, int c) {
            this->v = v;
            this->c = c;
        }
};

class Division {
    public:
        Division() {}
        Division(int n, int priority) {
            this->n = n;
            this->priority = priority;
        }

        bool operator() (const Division* d1, const Division* d2) const {
            return d1->priority > d2->priority;
        }

        int priority;
        int n;
};

vector<Division*> changedDivs[MAX_N];

class City {
    public:
        City() {}
        City(int n, int priority) {
            visited = false;
            divs.push(new Division(n, priority));
            finished = n == 1;
            days = 0;
        }

        bool visited;
        vector<Edge*> edges;
        Edge* e;
        priority_queue<Division*, vector<Division*>, Division> divs;
        int finished;
        int days;
};

City city[MAX_N];

void findDirs(int prev, int v) {
    city[v].visited = true;
    for (int i = 0; i < city[v].edges.size(); ++i) {
        Edge* edge = city[v].edges[i];
        if (prev != -1 && edge->v == prev) {
            city[v].e = edge;
        }
        if (!city[edge->v].visited) {
            findDirs(v, edge->v);
        }
    }
}

void solve() {
    while (city[1].divs.size() < n) {
        for (int i = 1; i <= n; ++i) {
            changedDivs[i].clear();
        }

        for (int i = 1; i <= n; ++i) {
            if (!city[i].divs.empty()) {
                int c = city[i].e->c;
                int v = city[i].e->v;

                int j = 0;
                while (!city[i].divs.empty() && j < c) {
                    ++j;
                    Division* div = city[i].divs.top();
                    city[i].divs.pop();
                    changedDivs[v].push_back(div);
                }
            }
        }

        for (int i = 2; i <=n; ++i)
        {
            if (!city[i].finished) {
                ++city[i].days;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < changedDivs[i].size(); ++j) {
                if (i == 1) {
                    int num = changedDivs[1][j]->n;
                    city[num].finished = true;
                }
                city[i].divs.push(changedDivs[i][j]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int priority;
        scanf("%d", &priority);
        city[i] = City(i, priority);
    }
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        city[a].edges.push_back(new Edge(b, c));
        city[b].edges.push_back(new Edge(a, c));
    }
    findDirs(-1, 1);

    solve();
    for (int i = 1; i <= n; ++i) {
        printf("%d ", city[i].days);
    }
    printf("\n");

    return 0;
}
