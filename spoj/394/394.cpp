#include <cstdio>
#include <utility>
#include <cstring>

using namespace std;

const int MAXN = 5005;

long long calc(char* s)
{
    int len = strlen(s);

    long long a = 1;
    long long b = 1;

    for (int i = 1; i < len; ++i)
    {

        if (s[i] == '0')
        {
            b = 0;
        }
        else
        {
            long long tmp = b;
            b = a;
            int n = (s[i-1]-'0')*10+s[i]-'0';
            if (n <= 26)
                a = b+tmp;
            else
                a = b;
        }
    }

    return a;
}

int main()
{
    char s[MAXN];
    while (1)
    {
        scanf("%s", s);
        if (*s == '0')
            break;

        printf("%lld\n", calc(s));
    }
    return 0;
}
