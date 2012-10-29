#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;

const long long MOD = 1000000007LL;

class NoRepeatPlaylist {
public:
  long long N, M, P;
  long long dp[150][150];

  long long solve(long long n, long long p) {
    if (n == 0 && p == 0) return 1;
    if (n == 0 || p == 0) return 0;
    if (dp[n][p] != -1)
      return dp[n][p];

    long long ret = 0;

    if (n-M > 0) ret += solve(n, p-1) * (n-M);
    if (n-1 >= 0) ret += solve(n-1, p-1) * (N-(n-1));

    dp[n][p] = ret % MOD;
    return dp[n][p];
  }

  long long numPlaylists(long long N, long long M, long long P) {
    this->N = N;
    this->M = M;
    this->P = P;
    for (long long i = 0; i < 150; ++i)
      for (long long j = 0; j < 150; ++j)
        dp[i][j] = -1;
    dp[0][0] = 1;
    for (long long i = 0; i < 150; ++i) {
      dp[i][0] = 0;
      dp[0][i] = 0;
    }
    return solve(N, P);
  }


// BEGIN CUT HERE
	public:
	void run_test(long long Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(long long Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1; long long Arg1 = 0; long long Arg2 = 3; long long Arg3 = 1; verify_case(0, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1; long long Arg1 = 1; long long Arg2 = 3; long long Arg3 = 0; verify_case(1, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 2; long long Arg1 = 0; long long Arg2 = 3; long long Arg3 = 6; verify_case(2, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 4; long long Arg1 = 0; long long Arg2 = 4; long long Arg3 = 24; verify_case(3, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 2; long long Arg1 = 1; long long Arg2 = 4; long long Arg3 = 2; verify_case(4, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 50; long long Arg1 = 5; long long Arg2 = 100; long long Arg3 = 222288991; verify_case(5, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NoRepeatPlaylist ___test;
	___test.run_test(-1);
}
// END CUT HERE
