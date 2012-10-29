#include <cstdio>
#include <string>

const int MAX_N = 1000005;

int kmp[MAX_N], r, t[MAX_N], tmp[MAX_N], sum[MAX_N];
char p[MAX_N];
long long result, x;

void calculateKMP()
{
	kmp[0] = 0;
	int q = 0;
	for (int i = 1; p[i]; ++i)
	{
		while (q > 0 && p[q] != p[i])
			q = kmp[q-1];
		if (p[q] == p[i])
			++q;
		kmp[i] = q;
	}
}

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    scanf("%s", p);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    calculateKMP();
    r = m;
    if (kmp[m - 1] && (kmp[m - 1] % (m - kmp[m - 1]) == 0)) {
        r = m - kmp[m - 1];
        for (int i = 0; i < n; ++i)
            t[i] %= r;
    }
    for (int i = 0; i < n; ++i)
        tmp[t[i]]++;
//    for (int i = 1; i < n; ++i)
//        sum[i] = sum[i - 1] + tmp[i] * i;
    result = 1000000000005LL;
    for (int i = 0; i <= r; ++i) {
//        printf("%d\n", tmp[i]);
        x = 0;
        for (int j = 0; j <= r; ++j)
            x += min(abs(i-j), r-abs(i-j)) * tmp[j];
        if (x < result)
            result = x;
    }
    printf("%lld\n", result);
	return 0;
}
