#include <cstdio>
#include <cstring>

const int MAX_R = 105;
const int MAX_C = 2 * 105;

bool even(int r) {
    return (r & 1) == 0;
}

void calc_prob(double prob[MAX_R][MAX_C], bool missing[MAX_R][MAX_C], int R, int C, int K) {
    memset(prob, 0, sizeof(prob));
    prob[R-1][2 * K] = 1.0f;

    for (int r = R-2; r >= 0; --r) {
        for (int c = 0; c < 2 * (C - 1) - 1; ++c) {
            if (even(r)) {
                if (even(c)) {
                    if (missing[r+1][c]) {
                        prob[r][c] = prob[r+1][c];
                    } else {
                        if (c == 0) {
                            prob[r][c] = prob[r+1][c+1];
                        } else if (c == 2 * (C - 1) -1) {
                            prob[r][c] = prob[r+1][c-1];
                        } else {
                            prob[r][c] = (prob[r+1][c-1] + prob[r+1][c+1]) / 2.0f;
                        }
                    }
                } else if (!even(c) && missing[r][c]) {
                    prob[r][c] = prob[r+1][c];
                }
            } else {
                if (!even(c)) {
                    if (missing[r+1][c]) {
                        prob[r][c] = prob[r+1][c];
                    } else {
                        prob[r][c] = (prob[r+1][c-1] + prob[r+1][c+1]) / 2.0f;
                    }
                } else if (even(c) && missing[r][c]) {
                    prob[r][c] = prob[r+1][c];
                }
            }
        }
    }
}

int main() {
    int N;
    int R, C;
    int K;
    int M;
    int r, c;
    bool missing[MAX_R][MAX_C];
    double prob[MAX_R][MAX_C];

    scanf("%d", &N);
    while (N--) {
        memset(missing, 0, sizeof(missing));
        memset(prob, 0, sizeof(prob));

        scanf("%d %d %d %d", &R, &C, &K, &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &r, &c);
            if (even(r)) {
                if (c != 0 && c != C-1) {
                    missing[r][2 * c - 1] = true;
                }
            } else {
                missing[r][2 * c] = true;
            }
        }

        calc_prob(prob, missing, R, C, K);

        int result_col = 1;
        for (int c = 0; c < 2 * (C - 1) - 1; ++c) {
            if (prob[0][result_col] < prob[0][c]) {
                result_col = c;
            }
        }

        printf("%d %.6lf\n", (int) (result_col / 2), prob[0][result_col]);
    }
    return 0;
}
