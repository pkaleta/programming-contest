#include <stdio.h>

const int MAX_WEIGHT = 10005;
const int MAX_COINS = 505;
const int INFINITY = 500000005;

inline int min(int a, int b)
{
	return (a < b ? a : b);
}

int main()
{
	int t, e, f, n, tab[MAX_WEIGHT], coins[MAX_COINS][2], tmp;

	scanf("%d", &t);
	tab[0] = 0;
	while (t--)
	{
		scanf("%d%d%d", &e, &f, &n);
		tmp = f-e;
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &coins[i][0], &coins[i][1]);
		for (int i = 1; i <= tmp; ++i)
			tab[i] = INFINITY;
		for (int i = 1; i <= tmp; ++i)
			for (int j = 0; j < n; ++j)
				if (i-coins[j][1] >= 0 && tab[i-coins[j][1]] != INFINITY)
					tab[i] = min(tab[i], tab[i-coins[j][1]]+coins[j][0]);
		if (tab[tmp] < INFINITY)
			printf("The minimum amount of money in the piggy-bank is %d.\n", tab[tmp]);
		else
			printf("This is impossible.\n");
	}
	return 0;
}
