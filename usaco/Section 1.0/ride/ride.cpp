/*
ID: piotrek4
LANG: C
TASK: ride
*/

#include <stdio.h>

int main() 
{
    FILE *fin  = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    int a, b;
    char c;
    while (1 == fscanf(fin, "%c", &c))
    {
        a = b = 1;
        while (c != '\n')
        {
            printf("%c - %d\n", c, c - 'A' + 1);
            a *= (c - 'A' + 1);
            a %= 47;
            fscanf(fin, "%c", &c);
        }
        fscanf(fin, "%c", &c);
        while (c != '\n')
        {
            printf("%c - %d\n", c, c - 'A' + 1);
            b *= (c - 'A' + 1);
            b %= 47;
            fscanf(fin, "%c", &c);
        }
        printf("%d %d\n", a, b);
        if (a == b) 
            fprintf(fout, "GO\n");
        else
            fprintf(fout, "STAY\n");
    }
    return 0;
}


