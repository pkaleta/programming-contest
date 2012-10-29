#include <stdio.h>
#include <math.h>

int main (void)
{
int z;
scanf("%d\n", &z);
while (z--)
{
int n;
int a;
long double res = 0;
bool zero = false;
scanf("%d\n",&n);
for (int i = 0; i < n; ++i)
{
scanf("%d",&a);
if (a != 0)
res += log10(a);
else
zero = true;
}
if (zero)
printf("1\n");
else
printf("%d\n",int(res)+1);
}
return 0;
}
