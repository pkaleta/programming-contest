#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Event {
    bool type;
    int time;
};

vector<Event*> t;

bool cmp(Event* a, Event* b) {
    if (a->time < b->time)
        return true;
    if (a->time > b->time)
        return false;
    if (a->time == b->time)
        return a->type < b->type;
}

int main() {
    int b;
    int x, y;
    int res = 0;

    scanf("%d", &b);
    for (int i = 0; i < b; ++i) {
        scanf("%d %d", &x, &y);
        Event* e = new Event();
        e->time = x;
        e->type = true;
        t.push_back(e);

        e = new Event();
        e->time = y;
        e->type = false;
        t.push_back(e);
    }
    sort(t.begin(), t.end(), cmp);

    int curr = 0;
    vector<Event*>::iterator i;
    for (i = t.begin(); i != t.end(); ++i) {
        if ((*i)->type) {
            ++curr;
            if (curr > res)
                res = curr;
        }
        else
            --curr;
    }

    printf("%d\n", res);

    return 0;
}
