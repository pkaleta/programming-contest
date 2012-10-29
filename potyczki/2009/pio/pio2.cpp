#include <cstdio>
#include <cstdlib>
#include <list>
#include <set>

using namespace std;

const int MAX_M 1100005;
const int MAX_N = 100005;

class Line {
    public:
        bool color;
        int a;
        int b;
        int* parent;
        Line(int _a, int _b, bool _color) :
            a(_a), b(_b), color(_color), parent(NULL) {}
}

list<Line*> white;
list<Line*> black;
list<List*>[MAX_N] whiteRows;
list<List*>[MAX_N] blackRows;

int findUpper(int a, int b) {}

void merge(List* l1, List* l2) {
    l2->parent = l1->parent;
}

int main() {

    int n, m, p;
    int w, k1, k2;

    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &w, &k1, &k2);
        Line* line = new Line(k1, k2, true);
        blackRows[w].push_back(line);
    }

    int current = 1;

    for (int i = 0; i < n; ++i) {
        int last = -1;
        list<Line*>::iterator j;

        for (j = blackRows[i].begin(); j != blackRows[i].end(); ++j) {
            List* row = (*j);

            if (i != 0) {
                
            }

            if (last == -1) {
                Line* line = new Line(0, 
                whiteRows[i].push_back(
            } else {

            }
        }
    }

    return 0;
}
