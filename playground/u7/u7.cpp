#include <stdio.h>
#include <string.h>

const int MAX_LEN = 2000005;

int main()
{
	char s[MAX_LEN];
	int z;

	scanf("%d", &z);
	while (z--)
	{
		scanf("%s ", &s);
		char c;
		int i = 0, j = 0;
		while (scanf("%c", &c) && c != '\n')
		{
			if (s[i] == c)
				++i;
			++j;
		}
		if (i == strlen(s))
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	return 0;
}
