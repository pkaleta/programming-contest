#include <cstdio>
#include <cstdlib>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool point_in_grid(int x1, int y1, int v)
{
    return (x1 % v == 0 && y1 % v == 0);
}

int main()
{
    int t;
    int n, k, x1, y1, x2, y2;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d %d %d %d %d", &k, &n, &x1, &y1, &x2, &y2);
        int x = abs(x2 - x1);
        int y = abs(y2 - y1);
        int v = gcd(2 * k, 2 * n);
        if (point_in_grid(k, n, v))
        {
            if (point_in_grid(x, y, v))
                printf("TAK\n");
            else
                printf("NIE\n");
        }
        else
        {
            int i = k % v;
            int j = n % v;
            int v1 = v / 2;

            if (i != 0 && j != 0)
            {
                if (point_in_grid(x, y, v))
                    printf("TAK\n");
                else
                {
                    if (point_in_grid((x - v1), (y - v1), v))
                        printf("TAK\n");
                    else
                        printf("NIE\n");
                }
            }
            else
            {
                if (point_in_grid(x, y, v1))
                    printf("TAK\n");
                else
                    printf("NIE\n");
            }
        }
    }
    return 0;
}
