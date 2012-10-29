#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;

const int MAX_N = 100005;

list<char> s;
char znak;
int c, cycles, chng, idnt;

int main()
{
    int i;
    list<char>::iterator I, J, K;
    scanf("%d\n", &c);
    while (c--)
    {
        cycles = 0;
        I = s.begin();
        while (!s.empty())
        {
            K = I;
            I++;
            s.erase(K);
        }
        while (1 == scanf("%c", &znak) && znak != '\n')
            s.push_back(znak);

        while (1)
        {
            chng = 0;
            I = s.begin();
            while (!s.empty() && (I != s.end()))
            {
                //printf("%c\n", (*I));
                if ((*I) == 'S')
                {
                    J = I;
                    J++;
                    K = J;
                    idnt = 0;
                    if ((*J) == 'B')
                    {
                        idnt = 1;
                        for (i = 0; i < 3; i++)
                        {
                            K++;
                            if ((*K) != 'B') idnt = 0;
                        }
                    }
                    
                    else if ((*J) == 'C')
                    {
                        idnt = 1;
                        for (i = 0; i < 3; i++)
                        {
                            K++;
                            if ((*K) != 'C') idnt = 0;
                        }
                    }
                    
                    if (idnt)
                    {
                        chng = 1;
                        (*I) = (*J);
                        for (i = 0; i < 4; i++)
                        {
                            K = J;
                            K++;
                            s.erase(J);
                            J = K;
                        }
                    }
                }
                I++;
            }
            if (!chng) break;
            cycles++;
        }
        for (I = s.begin(); I != s.end(); I++)
                printf("%c", (*I));
            printf(" ");
        printf("%d\n", cycles+1);
    }
    return 0;
}
