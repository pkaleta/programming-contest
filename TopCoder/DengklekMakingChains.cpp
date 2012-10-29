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


class DengklekMakingChains {
public:
  int maxBeauty(vector <string> chains) {
    vector<string> left;
    int ret = 0;
    int maxsingle = 0;

    for (int i = 0; i < chains.size(); ++i) {
      if (chains[i][1] != '.') {
        maxsingle = max(maxsingle, chains[i][1] - '0');
      }
      if (chains[i][0] != '.' && chains[i][1] != '.' && chains[i][2] != '.') {
        ret += chains[i][0] - '0' + chains[i][1] - '0' + chains[i][2] - '0';
      } else {
        left.push_back(chains[i]);
      }
    }

    int ans = 0;
    int tmp = 0;
    int k = 0;
    while (k < 3 && left[0][k] != '.') {
      ans += left[0][k] - '0';
      k++;
    }

    k = 2;
    while (k >= 0 && left[0][k] != '.') {
      tmp += left[0][k] - '0';
      k--;
    }
    ans = max(ans, tmp);

    for (int i = 0; i < left.size(); ++i) {
      for (int j = 0; j < left.size(); ++j) {
        if (i != j && left[i][0] != '.' && left[j][2] != '.') {
          int beg = 0;
          int k = 0;
          while (k < 3 && left[i][k] != '.') {
            beg += left[i][k] - '0';
            k++;
          }

          int end = 0;
          k = 2;
          while (k >= 0 && left[j][k] != '.') {
            end += left[j][k] - '0';
            k--;
          }
          ans = max(ans, beg+end);
        }
      }
    }
    return max(ret + ans, maxsingle);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"333", "8.8", "7.7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DengklekMakingChains ___test;
	___test.run_test(-1);
}
// END CUT HERE
