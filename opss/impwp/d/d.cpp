#include <stdio.h>
#include <math.h>

int main()
{
	int c, i, n, x;
	long double length;
	bool zero;
	scanf("%d", &c);
	while (c--)
	{	
		zero = false;
		length = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			if (x == 0)
				zero = true;
			else if (!zero)
				length += log10l(x);
		}
		if (zero)
			length = 0;
		printf("%d\n", int(length)+1);
	}
	return 0;
}
