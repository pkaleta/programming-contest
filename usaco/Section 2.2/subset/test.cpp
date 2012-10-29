#include <stdio.h>
#include <string.h>

#define MAXSUM 637

unsigned int numsets[637][51];

int max;
unsigned int sum;

main(int argc, char **argv)
{
    int lv, lv2, lv3;
    int cnt;
    FILE *fin, *fout;

    fin = fopen ("subset.in", "r");
    fscanf(fin, "%d", &max);
    fclose (fin);
    fout = fopen("subset.out", "w");

    if ((max % 4) == 1 || (max % 4) == 2) {
        fprintf (stderr, "0\n");
        return(1);
    }

    sum = max * (max+1) / 4;

    for (cnt = 0; cnt < 1; cnt++) {
        memset(numsets, 0, sizeof(numsets[0]));
        numsets[0][0] = 1;
        for (lv = 1; lv < max; lv++) {
            for (lv2 = 0; lv2 <= sum; lv2++)
                numsets[lv2][lv] = numsets[lv2][lv-1];
            for (lv2 = 0; lv2 <= sum-lv; lv2++)
                numsets[lv2+lv][lv] += numsets[lv2][lv-1];
        }

        fprintf (fout, "%u\n", numsets[sum][max-1]);
        fclose (fout);
    }
    return(0);
}
