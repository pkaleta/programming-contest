#include <stdio.h>

const int MAX_LEN = 100;

int main()
{
	int len = 0, t[MAX_LEN], n;
	bool divisible = true;
	scanf("%d", &n);
	while (n >= 10 && divisible)
	{
		int i = 9;
		divisible = false;
		while (i > 1)
		{
			if (!(n % i))
			{
				n /= i;
				t[len] = i;
				++len;
				divisible = true;
				break;
			}
			--i;
		}
	}
	if (!divisible)
		printf("-1\n");
	else if (!n)
		printf("10\n");
	else
	{
		printf("%d", n);
		for (int i = len - 1; i >= 0; --i)
			printf("%d", t[i]);
		printf("\n");
	}
	return 0;
}
