#include <cstdio>

const int MAXN = 100005;

int n;
int t[MAXN];

void read_data() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    t[n++] = t[0];
}

bool is_possible() {
    int greater = 0;
    int less = 0;

    for (int i = 1; i < n; ++i) {
        if (t[i] > t[i-1])
            greater++;
        if (t[i] < t[i-1])
            less++;
    }

    return less <= 1 || greater <= 1;
}

int main() {
    read_data();

    if (is_possible())
        printf("TAK\n");
    else
        printf("NIE\n");
    return 0;
}
