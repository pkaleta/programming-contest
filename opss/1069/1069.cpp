#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_SIZE = 205;

char t[MAX_SIZE];
int tlen;
vector<pair<char*, int> > words;

int len(char w[MAX_SIZE]) {
    int l = 0;
    while (w[++l]);
    return l;
}

int count(char word[MAX_SIZE]) {
    int c[MAX_SIZE][MAX_SIZE];
    int wlen = len(word);
    int tlen = len(t);
    int i, j;

    for (i = 0; i < MAX_SIZE; ++i)
        c[i][0] = c[0][i] = i;
    for (i = 1; i <= wlen; ++i)
        for (j = 1; j <= tlen; ++j)
            if (word[i - 1] == t[j - 1])
                c[i][j] = c[i - 1][j - 1];
            else
                c[i][j] = min(c[i - 1][j], min(c[i][j - 1], c[i - 1][j - 1])) + 1;
    return c[wlen][tlen];
}

bool cmp(pair<char*, int> a, pair<char*, int> b) {
    if (count(a.first) < count(b.first))
        return true;
    if (count(a.first) == count(b.first))
        return a.second < b.second;
    return false;
}

int main() {
    int d, n;

    scanf("%d\n", &d);
    while (d--) {
        words.clear();
        scanf("%s\n%d\n", t, &n);
        tlen = len(t);
        for (int i = 0; i < n; ++i) {
            pair<char*, int> p;
            p.first = new char[MAX_SIZE];
            p.second = i;
            scanf("%s\n", p.first);
            words.push_back(p);
        }
        sort(words.begin(), words.end(), cmp);

        for (int i = 0; i < n; ++i)
            printf("%s ", words[i].first);
        printf("\n");
    }
    return 0;
}
