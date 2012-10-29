#include <stdio.h>
#include <string.h>

const int MAX_LEN = 6005;
const int COINS_NUM = 11;

int main()
{
	int c[COINS_NUM] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
	long long t[MAX_LEN];
	double tmp;
	
	memset(t, 0, sizeof(t));
	t[0] = 1;
	for (int i = 0; i < COINS_NUM; ++i)
		for (int j = c[i]; j <= MAX_LEN; ++j)
			t[j] += t[j - c[i]]; 

	while (1 == scanf("%lf", &tmp) && tmp != 0)
	{
		int n = int(tmp * 100);
		int r = n / 5;
		printf("%6.2lf  %17lld\n", tmp, t[r]);
	}
	return 0;
}
