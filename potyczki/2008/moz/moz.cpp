#include <cstdio>

const int MAX_N = 305;
const int MAX_L = 100001;

int c[MAX_N][MAX_N];
int l[MAX_N];

struct List {
    char items1[MAX_N];
    char items2[MAX_N];
    int size;
} list[MAX_L];

int value(List& list, int i) {
    if (list.items1[i] == -1) {
        return list.items2[i] + 255;
    }
    else {
        if (list.items1[i] < 0)
            return list.items1[i] + 256;
        else
            return list.items1[i];
    }
}

int main() {
    int length, n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
        for (int j = 0; j < l[i]; ++j) {
            scanf("%d", &c[i][j]);
            if (i > 255) {
                list[c[i][j]].items1[list[c[i][j]].size] = -1;
                list[c[i][j]].items2[list[c[i][j]].size++] = i - 255;
            }
            else
                list[c[i][j]].items1[list[c[i][j]].size++] = i;
        }
    }
    for (int k = 0; k < n; ++k) {
        int sum = 0;
        for (int i = 0; i < l[k]; ++i)
            for (int j = i + 1; j < l[k]; ++j) {
//                printf("para: %d %d\n\n", c[k][i], c[k][j]);
                int v1 = c[k][i], v2 = c[k][j];
                int l1 = 0, l2 = 0;
                int a = 0, b = 0;
                while (l1 < list[v1].size) {
                    while (l2 < list[v2].size && value(list[v2], l2) < value(list[v1], l1))
                        ++l2;
                    if (l2 >= list[v2].size || (value(list[v2], l2) != value(list[v1], l1)))
                        ++a;
                    ++l1;
                }
                l1 = 0, l2 = 0;
                while (l2 < list[v2].size) {
                    while (l1 < list[v1].size && value(list[v1], l1) < value(list[v2], l2))
                        ++l1;
                    if (l1 >= list[v1].size || (value(list[v1], l1) != value(list[v2], l2)))
                        ++b;
                    ++l2;
                }
                sum += a * b;
            }
        printf("%d\n", sum);
    }
    return 0;
}
