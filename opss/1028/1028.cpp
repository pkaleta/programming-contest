#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 50005;
const int MAX_WORD_LENGTH = 31;

vector<char*> w;

bool lex_cmp(char* a, char* b) {
    return strcmp(a, b) < 0;
}

int length(const char* s) {
    int l = 0;
    while (*s++)
        ++l;
    for (int i = 0; i < l; ++i)
        --s;
    return l;
}

bool is_prefix(const char* s, const char* w) {
    while (*s && *w) {
        if (*s++ != *w++)
            return false;
    }
    return true;
}

char* reverse(const char* s) {
    char* rev = new char[MAX_WORD_LENGTH];
    memset(rev, 0, MAX_WORD_LENGTH);
    int a = 0;
    while (*s++)
        ++a;
    --s;
    char* tmp = rev;
    for (int i = 0; i < a; ++i)
        *rev++ = *--s;
    return tmp;
}

int main() {
    int c, h, n;

    scanf("%d\n", &c);
    while (c--) {
        scanf("%d\n%d\n", &h, &n);
        w.clear();
        for (int i = 0; i < n; ++i) {
            char* word = new char[MAX_WORD_LENGTH];
            scanf("%s\n", word);
            w.push_back(reverse(word));
        }

        sort(w.begin(), w.end(), lex_cmp);
        vector<char*>::iterator it = w.begin();
        char* prev = NULL;
        while (it != w.end()) {
            if (prev != NULL) {
                if (is_prefix(prev, *it)) {
                    w.erase(it);
                }
                else {
                    prev = *it;
                    ++it;
                }
            } else {
                prev = *it;
                ++it;
            }
        }
        int result = (int) pow(2, (double) h + 1) - 1;
        for (it = w.begin(); it != w.end(); ++it)
            result -= (int) pow(2, (double) (h - length(*it) + 1)) - 1;
        printf("%d\n", result);
    }
    return 0;
}
