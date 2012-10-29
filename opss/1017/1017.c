#include <stdio.h>
#include <string.h>

int MAX_LEN = 1000001;
int MAX_PARTS = MAX_LEN / 19 + 10;
unsigned long long MAX_PART_LEN = 1000000000000000000;

int main()
{
	int n;
	unsigned long long result[MAX_PARTS];
	memset(result, 0, sizeof(result))

	scanf("%d", &n);
	int currentPart = 1;
	int currentPosition = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a, int b;
		
		scanf("%d%d", &a, &b);
		int tmp = a + b;
		if (result[currentPart] >= MAX_PART_LEN)
			++currentPart;
			
		int tmpCurrentPart = currentPart;

		while (tmp)
		{
			if (result[tmpCurrentPart] < 1000000000000000000)
			{
				result[tmpCurrentPart] = result[tmpCurrentPart] * 10 + (tmp % 10);
				tmp /= 10;
			}
			else
				--currentPart;
		}
	}
	for (int i = 0; i <= currentPart; ++i)
		printf("%lld", result[i]);

	return 0;
}
