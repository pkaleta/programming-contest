/*
ID: piotrek4
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <string.h>

struct SName
{
    char txt[15];
    int difference;
} names[10];

int n;

void chng(char* name, int amount)
{
    int i = 0;
    while (strcmp(name, names[i].txt) != 0)
        ++i;
    names[i].difference += amount;
    printf("%s %d\n", name, amount);
}

int main() 
{
    int i, j, a, b, tmp;
    char name[15];

    FILE *fin  = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; ++i)
        fscanf(fin, "%s", names[i].txt);

    for (i = 0; i < n; ++i)
    {
        fscanf(fin, "%s%d%d", name, &a, &b);
        if (b > 0)
        {
            tmp = a / b;
            chng(name, -(tmp*b));
            for (j = 0; j < b; ++j)
            {
                fscanf(fin, "%s%d%d", name);
                chng(name, tmp);
            }
        }
    }
    for (i = 0; i < n; ++i)
        fprintf(fout, "%s %d\n", names[i].txt, names[i].difference);
    return 0;
}


