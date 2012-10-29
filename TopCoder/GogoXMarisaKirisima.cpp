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


class GogoXMarisaKirisima {
public:
  int solve(vector <string> cs) {
    vector<vector<int> > v;
    vector<vector<int> > orig;
    

    vector<vector<set<pair<int, int> > > > es;
    vector<vector<set<pair<int, int> > > > pes;

    for (int i = 0; i < cs.size(); ++i) {
      vector<int> x;
      vector<int> mmm;

      vector<set<pair<int, int> > > y;
      vector<set<pair<int, int> > > z;

      for (int j = 0; j < cs[i].size(); ++j) {
        x.push_back(cs[i][j] == 'Y');
        mmm.push_back(cs[i][j] == 'Y');
        y.push_back(set<pair<int, int> >());
      }
      v.push_back(x);
      orig.push_back(mmm);
      es.push_back(y);
      pes.push_back(z);
    }

    while(1) {
      cout << "***" << endl;
      int prev = es[0][v.size()-1].size();
      vector<vector<int> > tmp(v);
      for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
          v[i][j] = 0;
        }
      }

      for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
          for (int k = 0; k < v.size(); ++k) {
            
            v[i][j] += tmp[i][k] * orig[k][j];
            if (tmp[i][k] * orig[k][j] > 0) {
              int a = min(i, k);
              int b = max(i, k);
              es[i][j].insert(make_pair(a, b));

              a = min(k, j);
              b = max(k, j);
              es[i][j].insert(make_pair(a, b));
            }
          }
        }
      }
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cout << v[i][j] << " ";
        }
        cout << endl;
      }

      if (es[0][v.size()-1].size() == prev)
        break;
    }
    return v[0][v.size()-1];
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"YNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNY"
,"YNY"
,"YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYY"
,"NNNY"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXMarisaKirisima ___test;
	___test.run_test(-1);
}
// END CUT HERE
