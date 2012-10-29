#include <stdio.h>
#include <math.h>

int main()
{
	long long c, k, a, m, n;
	scanf("%lld", &c);
	while (c--)
	{
		m = 1;
		n = 0;
		scanf("%lld%lld", &k, &a);
		k = sqrt(k);
		printf("%lld\n", k*a);
	}
	return 0;
}
