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


class MagicDiamonds {
public:
  long long minimalTransfer(long long n) {
    map<unsigned long long, bool> isPrime;
    vector<long long> primes;
    isPrime[0] = isPrime[1] = false;
 

    // for (int p = 2; p <= n; ++p) {
    //   if (isPrime.find(p) == isPrime.end() || isPrime[p] == true) {
    //     isPrime[p] = true;
    //     primes.push_back(p);
    //     unsigned long long x = 2 * p;
    //     while (x <= n) {
    //       isPrime[x] = false;
    //       x += p;
    //     }
    //   }
    // }

    if (n == 1)
      return 1;
    if (n == 3)
      return 3;
    // if (n == 2)
    //   return 2;
    // else if (n == 3)
    //   return 2;
    // else if (n == 4)
    //   return 1;

    for (long long i = 2; i * i <= n; ++i) {
      if (n % i == 0)
        return 1;
    }
    return 2;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; verify_case(0, Arg1, minimalTransfer(Arg0)); }
	void test_case_1() { long long Arg0 = 4294967297LL; long long Arg1 = 1LL; verify_case(1, Arg1, minimalTransfer(Arg0)); }
	void test_case_2() { long long Arg0 = 2147483647LL; long long Arg1 = 2LL; verify_case(2, Arg1, minimalTransfer(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(3, Arg1, minimalTransfer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicDiamonds ___test;
	___test.run_test(-1);
}
// END CUT HERE
