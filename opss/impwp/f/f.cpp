#include <stdio.h>
#include <algorithm>

const int MAX_LEN = 105;

int main()
{
	int i, c, n, k, d;
	int b[MAX_LEN];

	scanf("%d", &c);
	while (c--)
	{
		scanf("%d%d%d", &n, &k, &d);
		for (i = 0; i < n-k; ++i)
			b[i] = 0;
		for (i = n-k; i < n; ++i)
			b[i] = 1;
		for (i = 0; i < d; ++i)
			std::next_permutation(b, b + n);
		for (i = 0; i < n; ++i)
			printf("%d", b[i]);
		printf("\n");
	}
	return 0;
}
