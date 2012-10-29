#include <stdio.h>
#include <math.h>
int main (void)
{
int z;
scanf("%d\n", &z);
while (z--)
{
int k,a;
scanf("%d %d\n",&k,&a);
k = sqrt(k);
long long res;
res = (long long)k * (long long)a;
printf("%lld\n", res);
}
return 0;
};
