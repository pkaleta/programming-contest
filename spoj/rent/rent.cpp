#include <stdio.h>
#include <stdlib.h>

const int MAX_LEN = 10005;

int s[MAX_LEN], f[MAX_LEN], d[MAX_LEN], p[MAX_LEN], ptr[MAX_LEN];

int compare(const void *a, const void *b)
{
	return (f[*(int*)a] - f[*(int*)b]);
}

int binarySearch(int l, int r, int begin)
{
	while (l < r)
	{
		int m = (l + r + 1) >> 1;
		if (f[ptr[m]] <= begin)
			l = m;
		else
			r = m - 1;
	}
	return l;
}

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int z, t[MAX_LEN];

	scanf("%d", &z);
	while (z--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d", &s[i], &d[i], &p[i]);
			f[i] = s[i] + d[i];
			ptr[i] = i;
		}
		qsort(ptr, n, sizeof(int), compare);
		t[0] = p[ptr[0]];
		for (int i = 1; i < n; ++i)
		{
			int j = binarySearch(0, i - 1, s[ptr[i]]);
			if (f[ptr[j]] <= s[ptr[i]])
				t[i] = max(t[i - 1], t[j] + p[ptr[i]]);
			else
				t[i] = max(t[i - 1], p[ptr[i]]);
		}
		printf("%d\n", t[n - 1]);
	}
	return 0;
}
