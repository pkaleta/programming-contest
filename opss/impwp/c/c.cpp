#include <stdio.h>

long long fib(long long n, long long m) 
{
	long long Ma = 1, Mb = 0, Mc = 1; 
	long long Va = 0, Vb = 1, Vc = 1; 
	for (; n; n >>= 1)
	{
    	if (n & 1) 
		{
      		long long Za = (((Ma * Va) % m) + ((Mb * Vb) % m)) % m;
      		long long Zb = (((Ma * Vb) % m) + ((Mb * Vc) % m)) % m; 
      		long long Zc = (((Mb * Vb) % m) + ((Mc * Vc) % m)) % m;
      		Ma = Za; Mb = Zb; Mc = Zc;
    	}
   		long long Za = (((Va * Va) % m) + ((Vb * Vb) % m)) % m;
    	long long Zb = (((Va * Vb) % m) + ((Vb * Vc) % m)) % m;
    	long long Zc = (((Vb * Vb) % m) + ((Vc * Vc) % m)) % m;
    	Va = Za; Vb = Zb; Vc = Zc;
  	}
  	return Mb;
}

int main() 
{
	long long c, a, b, n, m;
	scanf("%lld", &c);
	while (c--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
		printf("%lld\n", (((fib(n+2, m) * (b % m)) % m) + ((fib(n+1,m) * (a % m)) % m)) % m);
	}
}

