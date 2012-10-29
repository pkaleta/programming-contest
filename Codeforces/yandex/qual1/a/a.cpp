#include <cstdio>
#include <cstring>

const int MAX_LEN = 200005;

int main() {
    char s[MAX_LEN];
    char stack[MAX_LEN];
    int h = 0;

    scanf("%s", s);
    for (int i = 0; s[i] != 0; ++i) {
        if (h > 0 && s[i] == stack[h-1]) {
            --h;
        } else {
            stack[h++] = s[i];
        }
    }
    for (int i = 0; i < h; ++i) {
        s[i] = stack[i];
    }
    s[h] = 0;

    printf("%s\n", s);

    return 0;
}
