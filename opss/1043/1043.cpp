#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_LEN = 205;

char n[MAX_LEN];
char tmp[MAX_LEN];

void add(char* n, int m) {
    n[0] += m;
    int i = 0;
    while (n[i] >= 10) {
        n[i + 1] += n[i] / 10;
        n[i++] %= 10;
    }
}

bool divisible_by_2(char* n) {
    return n[0] % 2 == 0;
}

bool divisible_by_4(char* n) {
    return (n[0] + n[1] * 10) % 4 == 0;
}

void print(char* n) {
    int i = MAX_LEN - 1;
    while (i >= 0 &&  !n[i])
        --i;
    for (int j = i; j >= 0; --j)
        printf("%d", n[j]);
    printf("\n");
}

int main() {
    int t, len;
    char c;

    scanf("%d\n", &t);

    while (t--) {
        memset(n, 0, MAX_LEN);
        len = 0;
        scanf("%c", &c);
        while (c >= '0' && c <= '9') {
            tmp[len++] = c - '0';
            scanf("%c", &c);
        }
        for (int i = 0; i < len; ++i)
            n[len - i - 1] = tmp[i];

        while (1) {
            add(n, 1);
            if (divisible_by_2(n) && !divisible_by_4(n)) {
                print(n);
                break;
            }
        }
    }
    return 0;
}
