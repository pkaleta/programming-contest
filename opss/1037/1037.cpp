#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 13;
const int MAX_K = MAX_N * MAX_N;

int res[MAX_N][MAX_K] =
    {
        {1,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,0,0},
        {1,4,0,0,0,0,0,0,0,0,0,0,0},
        {1,9,8,0,0,0,0,0,0,0,0,0,0},
        {1,16,44,24,2,0,0,0,0,0,0,0,0},
        {1,25,140,204,82,10,0,0,0,0,0,0,0},
        {1,36,340,1024,982,248,4,0,0,0,0,0,0},
        {1,49,700,3628,7002,4618,832,40,0,0,0,0,0},
        {1,64,1288,10320,34568,46736,22708,3192,92,0,0,0,0},
        {1,81,2184,25096,131248,310496,312956,119180,13848,352,0,0,0},
        {1,100,3480,54400,412596,1535440,2716096,2119176,636524,56832,724,0,0},
        {1,121,5280,107880,1123832,6110256,17117832,23636352,14803480,3634976,264544,2680,0},
        {1,144,7700,199400,2739386,20609544,84871680,186506000,207667564,107305664,22146756,1375368,14200}
    };

bool intersect(int t[MAX_N], int n, int x, int y) {
    if (y == 0)
        return false;
    if (t[x] != 0)
        return true;
    for (int i = 1; i <= n; ++i) {
        if (i != x) {
            if (t[i] == y)
                return true;
            if (t[i] > 0 && abs(x - i) == abs(y - t[i]))
                return true;
        }
    }
    return false;
}

void calc(int t[MAX_N], int n, int m) {
    if (m <= n)
        ++res[n][t[0]];
    if (n < MAX_N - 1) {
        for (int i = 0; i < MAX_N; ++i) {
            if (!intersect(t, n + 1, n + 1, i)) {
                int b[MAX_N];
                memcpy(b, t, sizeof(int) * MAX_N);
                if (i)
                    ++b[0];
                b[n + 1] = i;
                int mm = max(m, i);
                calc(b, n + 1, mm);
            }
        }
    }
}

int main() {
    int c;
    int n, k;

//    int* board = new int[MAX_N];
//    memset(board, 0, sizeof(int) * MAX_N);
//    calc(board, 0, 0);
//    for (int i = 0; i < MAX_N; ++i) {
//        printf("{");
//        for (int j = 0; j < MAX_N; ++j) {
//            printf("%d", res[i][j]);
//            if (j != MAX_N-1)
//                printf(",");
//        }
//        printf("}\n");
//    }

    scanf("%d", &c);
    while (c--) {
        scanf("%d %d", &n, &k);
        printf("%d\n", res[n][k]);
    }
    return 0;
}
