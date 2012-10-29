/*
ID: piotrek4
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <string.h>
#define MIN_YEAR 1900

int main ()
{
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    int n, i, j, begin, days[7], months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    memset(days, 0, sizeof(days));
    fscanf(fin, "%d", &n);
    begin = 0;

    for (i = MIN_YEAR; i < MIN_YEAR+n; ++i)
    {

        if (!(i % 4))
        {
            if (!(i % 100))
            {
                if (!(i % 400))
                    months[1] = 29;
                else
                    months[1] = 28;
            }
            else
                months[1] = 29;
        }
        else
            months[1] = 28;
        for (j = 0; j < 12; ++j)
        {
            ++days[((begin+12)%7)];
            begin = (begin+months[j]-1)%7+1;
        }
    }
    fprintf(fout, "%d %d %d %d %d %d %d\n", days[5], days[6], days[0], days[1], days[2], days[3], days[4]);

    return 0;
}


