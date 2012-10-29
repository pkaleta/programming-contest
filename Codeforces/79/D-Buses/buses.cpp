#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

const int MAX_N = 1000000005;
const int MAX_M = 100005;
const int MOD = 1000000007LL;
vector<pair<int, int> > buses;
vector<int> ends;
long long dp[MAX_M];
long long sum[MAX_M];
int n, m;

void countWays() {
    for (int i = 0; i < m; ++i) {
        if (buses[i].second == 0) dp[i] = 1;

        int p = lower_bound(ends.begin(), ends.end(), buses[i].second)-ends.begin();
        int q = lower_bound(ends.begin(), ends.end(), buses[i].first)-ends.begin();

        long long x = 0;
        if (p > 0) x = sum[p-1];
        dp[i] = (dp[i] + (sum[q-1]-x+MOD)) % MOD;
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }
}

int main() {
    int s, t;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s, &t);
        pair<int, int> bus = make_pair(t, s);
        buses.push_back(bus);
        ends.push_back(t);
    }

    sort(buses.begin(), buses.end());
    sort(ends.begin(), ends.end());

    countWays();

    int j = lower_bound(ends.begin(), ends.end(), n)-ends.begin();

    long long ret = 0;
    for (int i = j; i < ends.size(); ++i) {
        ret = (ret + dp[i]) % MOD;
    }

    printf("%lld\n", ret);

    return 0;
}
