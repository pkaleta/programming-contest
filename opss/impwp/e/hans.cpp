#include <stdio.h>
#include <math.h>

int val[13][13];
bool free[13];
int min, max, n, p;
const int inf = 1000000;

void count(int k, int prev, int sum)
{
	if (k)
	{
		for (int i = 1; i <= n; ++i)
			if (free[i])
			{
				free[i] = false;
				count(k-1, i, sum + val[prev][i]);
				free[i] = true;
			}
	}
	else
	{
		sum += val[prev][p];
		if (sum > max)
			max = sum;
		if (sum < min)
			min = sum;
	}
}

int main (void)
{
	int z;
	scanf("%d\n", &z);
	while (z--)
	{
		int tmp;
		scanf("%d\n", &n);
		n *= 2;
		n = (sqrt(4*n+1) - 1)/2;
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j)
			{ 
				scanf("%d", &tmp);
				val[i][j] = val[j][i] = tmp;
			}
		scanf("%d\n", &p);
		min = inf;
		max = -inf;
		for (int i = 1; i <= 12; ++i)
			free[i] = true;
		free[p] = false;
		count(n-1,p,0);
		printf("%d %d\n", min, max);
	}
	return 0;
};
