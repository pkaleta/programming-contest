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


class ForbiddenStrings {
public:
  long long countNotForbidden(int n) {
    if (n == 1) return 3;
    if (n == 2) return 9;
    long long dp[35][9];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 9; ++i)
      dp[2][i] = 1;
    for (int i = 3; i <= n; ++i) {
      dp[i][0] = dp[i-1][0] + dp[i-1][3] + dp[i-1][6];
      dp[i][1] = dp[i-1][0] + dp[i-1][3];
      dp[i][2] = dp[i-1][0] + dp[i-1][6];
      dp[i][3] = dp[i-1][1] + dp[i-1][4];
      dp[i][4] = dp[i-1][1] + dp[i-1][4] + dp[i-1][7];
      dp[i][5] = dp[i-1][4] + dp[i-1][7];
      dp[i][6] = dp[i-1][2] + dp[i-1][8];
      dp[i][7] = dp[i-1][5] + dp[i-1][8];
      dp[i][8] = dp[i-1][2] + dp[i-1][5] + dp[i-1][8];
    }
    long long ret = 0;
    for (int i = 0; i < 9; ++i)
      ret += dp[n][i];
    return ret;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ForbiddenStrings ___test;
	___test.run_test(-1);
}
// END CUT HERE
