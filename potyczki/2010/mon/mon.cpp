#include <cstdio>
#include <algorithm>
#include <ext/hash_map>
namespace std { using namespace __gnu_cxx; }

using namespace std;
using namespace __gnu_cxx;

const int MAXN = 1000005;

struct hash_long_long {
    size_t operator() (const long long in)  const {
        long long ret = (in >> 32L) ^ (in & 0xFFFFFFFF);
        return (size_t) ret;
    }
};

int n, k;
char t[MAXN];
long long s[MAXN];
hash_map<long long, int, hash_long_long> h;

void read_data() {
    scanf("%d%d", &n, &k);
    scanf("%s", t);
}

int calculate() {
    int tmp, result = 0;

    s[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 'O')
            tmp = s[i+1] = s[i]-1;
        else
            tmp = s[i+1] = s[i]+k;

        if (tmp == 0)
            result = max(result, i+1);
        else if (h[tmp] == 0)
            h[tmp] = i+1;
        else {
            result = max(result, i+1-h[tmp]);
        }
    }
    return result;
}

int main() {
    read_data();

    printf("%d\n", calculate());

    return 0;
}
