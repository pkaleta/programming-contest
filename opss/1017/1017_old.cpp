#include <stdio.h>

const int BASE = 1000000000;
const int MAX_LEN = 112000;

int main()
{
	int n, a, b, sum[MAX_LEN], len;

	scanf("%d", &n);
	sum[0] = 0;
	len = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		int tmp = a + b;
		a = tmp / 10;
		b = tmp % 10;
		
		int j = len;
		tmp = sum[j];
		while (j >= 0 && a)
		{
			//printf("przenosze\n");
			int d = 1;
			int c = 0;
			while (a && c < 10)
			{
				int last = (sum[j] % 10 * d) / d;
				//printf("last = %d\n", last);
				if (last + a < 10)
				{
					sum[j] += d * a;
					a = 0;
					break;
				}
				else
				{
					//printf("jest\n");
					a = (last + a) / 10;
					sum[j] = sum[j] - (last * d) + ((last + a) % 10) * d;
				}
				d *= 10;
				++c;
			}
			--j;
		}
		//printf("test: %d\n", sum[len]);
		if ((long long)(sum[len]) * 10 + b >= BASE)
		{
			//printf("********\n");
			++len;
			sum[len] = b;
		}
		else
			sum[len] = sum[len] * 10 + b;
	}
	for (int k = 0; k <= len; ++k)
		printf("%d", sum[k]);
	printf("\n");
	return 0;
}
