#include <stdio.h>

// | a b |
// | c d |

int fib(int n) 
{
	int Ta = 1, Tb = 1, Tc = 1, Td = 0,
		Ra = 1, Rb = 1, Rc = 1, Rd = 0,
		a, b, c, d;

	for (; n; n >>= 1)
	{
		if (n & 1)
		{
			a = (Ra * Ta + Rb * Tc) % 10;
			b = (Ra * Tb + Rb * Td) % 10;
			c = (Rc * Ta + Rd * Tc) % 10;
			d = (Rc * Tb + Rd * Td) % 10;
			Ra = a, Rb = b, Rc = c, Rd = d;
		}
		a = (Ta * Ta + Tb * Tc) % 10;
		b = (Ta * Tb + Tb * Td) % 10;
		c = (Tc * Ta + Td * Tc) % 10;
		d = (Tc * Tb + Td * Td) % 10;
		Ta = a, Tb = b, Tc = c, Td = d;
	}
	return Rc;
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", fib(n));
	return 0;
}
