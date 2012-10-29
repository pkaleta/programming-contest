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


class Cut {
public:
  int getMaximum(vector <int> lens, int cuts) {
    vector<int> tens;
    vector<int> other;
    int ret = 0;
    for (int i = 0; i < lens.size(); ++i) {
      if (lens[i] % 10 == 0) {
        if (lens[i] == 10)
          ++ret;
        else
          tens.push_back(lens[i]);
      }
      else
        other.push_back(lens[i]);
    }
    sort(tens.begin(), tens.end());

    int i = 0;
    while (i < tens.size()) {
      int tmp = (tens[i] / 10) - 1;
      if (tmp > cuts) {
        ret += cuts;
        cuts = 0;
        break;
      } else if (tmp == cuts) {
        ret += cuts + 1;
        cuts = 0;
        break;
      } else {
        cuts -= tmp;
        ret += tmp + 1;
        ++i;
      }
    }
    i = 0;
    while (i < other.size()) {
      int tmp = (other[i] / 10);
      if (tmp >= cuts) {
        ret += cuts;
        break;
      } else {
        cuts -= tmp;
        ret += tmp;
        ++i;
      }
    }
    return ret;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {13, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {34, 10, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {30, 50, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 350; int Arg2 = 16; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cut ___test;
	___test.run_test(-1);
}
// END CUT HERE
