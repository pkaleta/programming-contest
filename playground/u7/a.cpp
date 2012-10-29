//Piotrek Kaleta

#include <stdio.h>
#include <string.h>

const int MAX_LEN = 2000002;

int main()
{
	int z, lcs[MAX_LEN], last, tmp;
	char a[MAX_LEN], b[MAX_LEN];
	scanf("%d\n", &z);
	while (z--)
	{
		scanf("%s%s", a, b);
		memset(lcs, 0, sizeof(lcs));
		for (int i = 0; a[i]; ++i)
		{
			last = 0;
			for (int j = 0; b[j]; ++j)
			{
				tmp = lcs[j+1];
				if (a[i] == b[j])
					lcs[j+1] = last+1;
				else if (lcs[j] > lcs[j+1])
					lcs[j+1] = lcs[j];

				last = tmp;
			}
		}
		if (lcs[strlen(b)] == strlen(a) || lcs[strlen(b)] == strlen(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
