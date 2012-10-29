#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char x[1000005];
    scanf("%s", x);
    int len = strlen(x);

    if (len == 1) {
        printf("0\n");
    } else {
        int ret = 0;
        int i = len-1;

        while (i+1 > 1) {
            if (x[i] == '1') {
                ++ret;
                while (i >= 0 && x[i] == '1') {
                    --i;
                    ++ret;
                }
                if (i >= 0) {
                    x[i] = '1';
                    x[i+1] = 0;
                } else {
                    break;
                }
            } else {
                ++ret;
                x[i] = 0;
                --i;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
