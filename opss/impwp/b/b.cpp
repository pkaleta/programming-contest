#include <stdio.h>

int main()
{
	int t, n;
	char c;
	scanf("%d\n", &t);
	while (t--)
	{
		n = 0;
		scanf("%c", &c);
		while (c != '\n')
		{
			n *= 2;
			if (c == '1')
				++n;
			if (n >= 3)
				n -= 3;
			scanf("%c", &c);
		}
		if (!n)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
