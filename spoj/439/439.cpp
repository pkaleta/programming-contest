#include <stdio.h>
#include <string.h>

const int MAX_COMPRESSED_LEN = 6000;
const int MAX_LEN = 10010;
const int BLOCK_LEN = 9;
const int MAX_BLOCK_VALUE = 999999999;
const int BLOCK_BASE = 1000000000;

long long l1[MAX_COMPRESSED_LEN], l2[MAX_COMPRESSED_LEN], len1, len2, i, result[MAX_COMPRESSED_LEN], resultLen;

void readNum()
{
	char tmp1[MAX_LEN], tmp2[MAX_LEN];
	int tmp1len, tmp2len, i, k, multiplier;
	long long *ptrnum, *ptrtmp;

	scanf("%s%s", tmp1, tmp2);
	tmp1len = strlen(tmp1);
	tmp2len = strlen(tmp2);
	len1 = len2 = 0;
	l1[MAX_COMPRESSED_LEN-1] = 0;
	multiplier = 1;
	ptrnum = l1 + (MAX_COMPRESSED_LEN-1)*8;
	for (i = tmp1len-1, k = 0; i >= 0; --i, ++k)
	{
		if (!(k % BLOCK_LEN))
		{
			++len1;
			ptrnum = 
			l1[MAX_COMPRESSED_LEN-len1] = 0;
			multiplier = 1;
		}
		l1[MAX_COMPRESSED_LEN-len1] += multiplier*(tmp1[i]-'0');
		multiplier *= 10;
	}
	
	multiplier = 1;
	l2[MAX_COMPRESSED_LEN-1] = 0;
	for (i = tmp2len-1, k = 0; i >= 0; --i, ++k)
	{
		if (!(k % BLOCK_LEN))
		{
			++len2;
			l2[MAX_COMPRESSED_LEN-len2] = 0;
			multiplier = 1;
		}
		l2[MAX_COMPRESSED_LEN-len2] += multiplier*(tmp2[i]-'0');
		multiplier *= 10;
	}
}

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

void multiply()
{
	int i, j, k, l, begin = MAX_COMPRESSED_LEN;

	resultLen = 0;
	k = MAX_COMPRESSED_LEN-1;
	for (i = MAX_COMPRESSED_LEN-1; i >= MAX_COMPRESSED_LEN-len1; --i)
	{
		k = i;
		for (j = MAX_COMPRESSED_LEN-1; j >= MAX_COMPRESSED_LEN-len2; --j)
		{
			result[k] += l1[i]*l2[j];
			if (k < begin)
				begin = k;
			l = k;
			while (result[l] > MAX_BLOCK_VALUE)
			{
				if (l-1 < begin)
					begin = l-1;
				result[l-1] += result[l]/BLOCK_BASE;
				result[l] %= BLOCK_BASE;
				--l;
			}
			--k;
		}
	}
	resultLen = MAX_COMPRESSED_LEN-begin+1;
}

void printResult()
{
	long long tmp;
	int i;
	tmp = result[MAX_COMPRESSED_LEN+1-resultLen];
	printf("%lld", tmp);
	if (tmp)
	{
		for (i = MAX_COMPRESSED_LEN+2-resultLen; i < MAX_COMPRESSED_LEN; ++i)
		{
			if (result[i] < 100000000)
				puts("0");
			if (result[i] < 10000000)
				puts("0");
			if (result[i] < 1000000)
				puts("0");
			if (result[i] < 100000)
				puts("0");
			if (result[i] < 10000)
				puts("0");
			if (result[i] < 1000)
				puts("0");
			if (result[i] < 100)
				puts("0");
			if (result[i] < 10)
				puts("0");
			printf("%lld", result[i]);
		}
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	memset(result, 0, sizeof(result));
	while (t--)
	{
		readNum();
		multiply();
		printResult();
		memset(result+(MAX_COMPRESSED_LEN-resultLen), 0, resultLen*8);
	}
	return 0;
}
