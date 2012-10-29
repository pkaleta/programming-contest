#include <stdio.h>
#include <string.h>

const int MAX_N = 70;
const int MAX_VALUE = 12;
const int MIN = 2000000;
const int MAX = -2000000;

int min, max, n, p, prevSum[MAX_VALUE], cost[MAX_N], range, 
value[MAX_VALUE][MAX_VALUE];
bool used[MAX_VALUE];

inline void calc(int left, int sum, int counter)
{
	if (counter)
	{
		for (int i = 1; i <= range; ++i)
		{
			if (!used[i])
			{
				used[i] = true;
				calc(i, sum+value[left][i], counter-1);
				used[i] = false;
			}
		}
	}
	else
	{
		sum += value[left][p];
		if (sum > max)
			max = sum;
		if (sum < min)
			min = sum;
	}
}

int main()
{
	int D[MAX_N] = {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 0, 5, 
0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 
0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 11};
	int i, j, c, tmp;
	
	scanf("%d", &c);
	while (c--)
	{
		memset(used, 0, sizeof(used));
		min = MIN;
		max = MAX;
		scanf("%d", &n);
		range = D[n];
		for (i = 1; i <= range; ++i)
			for (j = i; j <= range; ++j)
			{
				scanf("%d", &tmp);
				value[i][j] = value[j][i] = tmp;
			}
		scanf("%d", &p);
		used[p] = true;
		calc(p, 0, range-1);
		if (p > range)
			printf("0 0\n");
		else
			printf("%d %d\n", min, max);
	}
	return 0;
}

