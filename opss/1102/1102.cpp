#include <cstdio>

char t[26];

int main() {
    int z;

    for (char c = 'A'; c <= 'Z'; ++c) {
        t[c - 'A'] = (c - 'A') / 3 + 2;
    }
    t['S' - 'A'] = 7;
    t['V' - 'A'] = 8;
    t['Y' - 'A'] = 9;
    t['Z' - 'A'] = 9;

    scanf("%d\n", &z);
    while (z--) {
        char c;
        scanf("%c", &c);
        while (c >= 'A' && c <= 'Z') {
            printf("%d", t[c - 'A']);
            scanf("%c", &c);
        }
        printf("\n");
    }
    return 0;
}
