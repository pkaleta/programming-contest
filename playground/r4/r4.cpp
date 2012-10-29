#include <stdio.h>

int main()
{
	int n, a = 0, b = 0, c = 0, x;

	scanf("%d%d", &n, &c);
	n--;
	while (n--)
	{
		scanf("%d", &x);
		printf("wczytalem: %d\n", x);
		printf("a: %d b: %d c: %d\n", a, b, c);
		if (a + b > c)
		{
			printf("%d %d %d\n", a, b, c);
			break;
		}
	}
	if (n <= 0)
		printf("NIE\n");
	return 0;
}
