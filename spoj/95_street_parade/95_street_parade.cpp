#include <cstdio>

const int max_n = 1005;

int stack[max_n];
int h;

void push(int x) {
    stack[h++] = x;
}

void pop() {
    --h;
}

int top() {
    return stack[h-1];
}

int main() {
    int cur, n, x;

    while(scanf("%d", &n) && n) {
        h = 0;
        cur = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (x != cur) {
                while (h > 0 && top() == cur) {
                    ++cur;
                    pop();
                }
                push(x);
            } else {
                ++cur;
            }
        }
        while (h > 0 && top() == cur) {
            ++cur;
            pop();
        }
        if (h > 0)
            printf("no\n");
        else
            printf("yes\n");
    }
}
