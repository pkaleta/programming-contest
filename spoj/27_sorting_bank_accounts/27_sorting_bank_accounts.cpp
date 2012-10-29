#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KONT 100005
#define ILE_CYFR 45

char konto[MAX_KONT][ILE_CYFR];
int tab[MAX_KONT];
int ile[MAX_KONT];

int cmp(const void *a, const void *b)
{
	return strcmp(konto[*(int *)a], konto[*(int *)b]);
}

int main(void)
{
	int t, ile_testow, ile_kont, k, j;
	scanf("%d", &ile_testow);
	for (t = 0; t < ile_testow; t++)
	{
		scanf("%d\n", &ile_kont);
		for (k = 0; k < ile_kont; k++)
			scanf("%s", konto[k]);
		for (k = 0; k < ile_kont; k++)
			tab[k] = k;
		memset(ile, 0, sizeof(ile));
		qsort(tab, ile_kont, sizeof(int), cmp);
		k = 0;
		ile[tab[k]] = 1;
		j = 1;
		while (1)
		{
			ile[tab[k]] = 1;
			while (strcmp(konto[tab[k]], konto[tab[j]]) == 0 && j < ile_kont)
			{
				ile[tab[k]]++;
				j++;
			}
			if (j >= ile_kont) break;
			k = j;
			ile[tab[k]] = 1;
			j = k + 1;
		}
		for (k = 0; k < ile_kont; k++)
		{
			if (ile[tab[k]] > 0)
			{
				printf("%s %d\n", konto[tab[k]], ile[tab[k]]);
			}
		}
		if (t != ile_testow-1) printf("\n");
	}
	return 0;
}
