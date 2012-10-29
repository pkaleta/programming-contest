#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (b > 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    int d;
    char tmp[1000];
    long long t[3][2];
    long long r[3];
    int len[2];

    scanf("%d\n", &d);
    while (d--) {
        len[0] = 1;
        len[1] = 1;
        scanf("%s\n", &tmp);
        int i = 0;
        int j = 0;
        int k = 0;
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 2; ++y)
                t[x][y] = -1;
        while (tmp[i]) {
            if (tmp[i] == '+') {
                j = 0;
                ++k;
            } else {
                if (tmp[i] == '/') {
                    ++len[k];
                    ++j;
                } else {
                    if (t[j][k] == -1)
                        t[j][k] = 0;
                    t[j][k] = t[j][k] * 10 + tmp[i] - '0';
                }
            }
            ++i;
        }
        for (int y = 0; y < 2; ++y) {
            if (len[y] == 1) {
                t[1][y] = t[0][y];
                t[2][y] = 1;
                t[0][y] = 0;
            }
            if (len[y] == 2) {
                t[2][y] = t[1][y];
                t[1][y] = t[0][y];
                t[0][y] = 0;
            }
            if (len[y] == 3) {
                t[1][y] += t[0][y] * t[2][y];
                t[0][y] = 0;
            }
        }

        r[0] = r[1] = r[2] = 0;
        r[2] = lcm(t[2][0], t[2][1]);

        r[1] = t[1][0] * r[2] / t[2][0] + t[1][1] * r[2] / t[2][1];

        r[0] = r[1] / r[2];
        r[1] = r[1] % r[2];

        long long g = gcd(r[1], r[2]);

        r[1] /= g;
        r[2] /= g;

//        for (int y = 0; y < 2; ++y) {
//            for (int x = 0; x < 3; ++x)
//                printf("%lld, ", t[x][y]);
//            printf("\nlen: %d\n", len[y]);
//        }
//        printf("result:\n");
//        for (int x = 0; x < 3; ++x)
//            printf("%lld, ", r[x]);
//        printf("\n");

        if (r[0] > 0) {
            printf("%lld", r[0]);
            if (r[1] > 0)
                printf("/");
        } else if (r[1] == 0) {
            printf("%lld", r[0]);
        }
        if (r[1] > 0) {
            printf("%lld/", r[1]);
            printf("%lld", r[2]);
        }
        printf("\n");
    }
    return 0;
}
