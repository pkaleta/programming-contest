#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX_NOM =105;
const int MAX_KWOTA = 1005;

greater<int> g;
int c, n, k, nom[MAX_NOM], sum, num, tab[MAX_KWOTA], tmp[MAX_KWOTA];

int main()
{
    int i, j, k;
    scanf("%d", &c);
    while (c--)
    {
        sum = 0;
        num = 0;
        scanf("%d%d", &n, &k);
        for (i = 0; i < k; i++) scanf("%d", &nom[i]);
        sort(nom, nom+k, g);
        for (i = 0; i < MAX_KWOTA; i++) tab[i] = 100000;
        tab[0] = 0;

        for (i = 0; i <= n; i++)
            if (tab[i] >= 0 && tab[i] < 100000)
                for (j = 0; j < k; j++)
                {
                    if (tab[i+nom[j]] > tab[i]+1)
                        tab[i+nom[j]] = tab[i]+1;
                }
        if (tab[n] < 100000) printf("%d\n", tab[n]);
        else printf("0\n");
    }
    return 0;
}
