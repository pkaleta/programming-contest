#include <stdio.h>
#include <string.h>

const int MAX_LEN = 800;
const int BASE = 10000;

int main()
{
	int result[MAX_LEN];
	int c, n, i, j, k, begin, x, tmp;
	
	scanf("%d", &c);
	while (c--)
	{
		memset(result, 0, sizeof(result));
		scanf("%d%d", &n, &x);
		result[MAX_LEN-1] = x;
		begin = MAX_LEN-1;
		for (i = 1; i < n; ++i)
		{
			scanf("%d", &x);
			tmp = 0;
			for (j = MAX_LEN-1; j >= begin; --j)
			{
				result[j] = result[j]*x + tmp;
				tmp = 0;
				if (result[j] >= BASE)
				{
					tmp = result[j]/BASE;
					result[j] %= BASE;
				}
			}
			result[j] += tmp;
			if (x == 0)
				begin = MAX_LEN-1;
			else if (result[begin-1] > 0)
				--begin;
		}
		if (result[begin] < 10)
			printf("%d\n", (MAX_LEN-1-begin)*4+1);
		else if (result[begin] < 100)
			printf("%d\n", (MAX_LEN-1-begin)*4+2);
		else if (result[begin] < 1000)
			printf("%d\n", (MAX_LEN-1-begin)*4+3);
		else
			printf("%d\n", (MAX_LEN-1-begin)*4+4);
	}
	return 0;
}
