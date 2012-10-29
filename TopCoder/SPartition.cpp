#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>


using namespace std;


class SPartition {
public:

  string s;
  int limit;

  long long binomial(long long n, long long k) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    return binomial(n-1, k-1) + binomial(n-1, k);
  }

  int solve(string a, string b, int i) {
    if (i < limit) {
      string aa = a;
      string bb = b;
      while (a.size() < s.size() / 2) {
        a = s[0] + a;
      }
      while (b.size() < s.size() / 2) {
        b = s[0] + b;
      }
      if (a == b) {
        int left = s.size() / 2 - aa.size();
        return binomial(limit, left);
      }
      else
        return 0;
    }

    if (i < 0) return a == b;
    if (a.size() > 0 && b.size() > 0) {
      if (a.size() == b.size()) {
        if (a[0] != b[0]) return 0;
      } else if (a.size() > b.size()) {
        if (b[0] != a[a.size()-b.size()]) return 0;
      } else if (b.size() > a.size()) {
        if (a[0] != b[b.size()-a.size()]) return 0;
      }
    }
    if (a.size() == s.size() / 2) {
      if (s.substr(0, s.size() / 2 - b.size()) + b == a) return 1;
      else return 0;
    }
    if (b.size() == s.size() / 2) {
      if (s.substr(0, s.size() / 2 - a.size()) + a == b) return 1;
      else return 0;
    }

    return solve(s[i] + a, b, i-1) + solve(a, s[i] + b, i-1);
  }

  long long getCount(string s) {
    this->s = s;
    int i = s.size()-1;
    this->limit = 0;
    while (s[++limit] == s[0]);
    return 2 * solve(s.substr(s.size()-1, 1), "", s.size()-2);
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxox"; long long Arg1 = 2LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arg0 = "oooxxx"; long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arg0 = "xoxxox"; long long Arg1 = 4LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arg0 = "xo"; long long Arg1 = 0LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arg0 = "ooooxoox"; long long Arg1 = 8LL; verify_case(4, Arg1, getCount(Arg0)); }
	void test_case_5() { string Arg0 = "ooooooooooooooooooooooooooooooooooooooxx"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SPartition ___test;
	___test.run_test(-1);
}
// END CUT HERE
