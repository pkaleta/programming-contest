#include <stdio.h>
#include <string.h>

const int MAX_LEN = 36;

int main()
{
	int t, r, s, tmp, len, dec;
	char n1[MAX_LEN];
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%d%d", n1, &r, &s);
		len = strlen(n1);
		tmp = 1;
		dec = 0;
		for (int i = len-1; i >= 0; --i)
		{
			if (n1[i] >= 'A' && n1[i] <= 'Z')
				dec += (n1[i]-'A'+10)*tmp;
			else
				dec += (n1[i]-'0')*tmp;
			tmp *= r;
		}
		printf("%d\n", dec);

	}
	return 0;
}
