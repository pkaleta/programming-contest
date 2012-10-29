#include <stdio.h>

const int MAX_LEN = 100005;

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int z, n, a, b, c, aTmp, bTmp, cTmp, tmp;

	scanf("%d", &z);
	while (z--)
	{
		scanf("%d%d", &n, &tmp);
		a = 0;
		b = c = tmp;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &tmp);
			aTmp = max(a, max(b, c));
			bTmp = a + tmp;
			cTmp = b + tmp;
			a = aTmp;
			b = bTmp;
			c = cTmp;
		}
		printf("%d\n", max(a, max(b, c)));
	}
	return 0;
}
