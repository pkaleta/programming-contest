#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int max_n = 55;
const int max_t = 1005;

int main() {
    int n, t;
    int times[max_n][max_n];
    int dist[max_n][max_n];
    int dp[max_n][max_t];
    bool inqueue[max_n];

    queue<int> q;
    while (scanf("%d%d", &n, &t) && n && t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &times[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &dist[i][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < t; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i <= t; ++i) {
            dp[0][i] = 0;
        }

        memset(inqueue, 0, sizeof(inqueue));

        inqueue[0] = true;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            inqueue[v] = false;
            q.pop();

            for (int i = 0; i < n; ++i) { // sasiedzi
                if (i != v) {
                    for (int j = 0; j <= t; ++j) { // czasy
                        if (dp[v][j] >= 0) {
                            int m = dp[i][j+times[v][i]];
                            if (m < 0 || m > dp[v][j]+dist[v][i]) {
                                if (!inqueue[i]) {
                                    q.push(i);
                                    inqueue[i] = true;
                                }
                                dp[i][j+times[v][i]] = dp[v][j]+dist[v][i];
                            }
                        }
                    }
                }
            }
        }

        int result = -1;
        for (int i = 1; i < t; ++i) {
            if (dp[n-1][i] >= 0 && (result == -1 || dp[n-1][result] > dp[n-1][i])) {
                result = i;
            }
        }
        printf("%d %d\n", dp[n-1][result], result);

        //for (int i = 0; i < n; ++i) {
        //    for (int j = 0; j <= t; ++j) {
        //        printf("%d ", dp[i][j]);
        //    }
        //    printf("\n");
        //}
    }
    return 0;
}
