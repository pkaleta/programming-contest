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


class DropCoins {
public:

  vector<string> board;

  struct State {
    State(int _m, int _k, int _el, int _er, int _eu, int _ed, int _l, int _r, int _u, int _d) {
      m = _m;
      k = _k;
      el = _el;
      er = _er;
      eu = _eu;
      ed = _ed;
      l = _l;
      r = _r;
      u = _u;
      d = _d;
    }

    int k;
    int el, er, eu, ed;
    int l, r, u, d;
    int m;
  };

  int solve(int left, int goal) {
    queue<State*> q;

    int el, er, eu, ed;
    el = eu = 0;
    er = ed = 0;
    
    for (int i = 0; i < board.size(); ++i) {
      bool found = false;
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'o') found = true;
      }
      if (found) break;
      ++eu;
    }
    
    for (int i = board.size()-1; i >= 0; --i) {
      bool found = false;
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'o') found = true;
      }
      if (found) break;
      ++ed;
    }
    
    for (int i = 0; i < board[0].size(); ++i) {
      bool found = false;
      for (int j = 0; j < board.size(); ++j) {
        if (board[j][i] == 'o') found = true;
      }
      if (found) break;
      ++el;
    }
    
    for (int i = board[0].size()-1; i >= 0; --i) {
      bool found = false;
      for (int j = 0; j < board.size(); ++j) {
        if (board[j][i] == 'o') found = true;
      }
      if (found) break;
      ++er;
    }

    q.push(new State(0, left, el, er, eu, ed, 0, board[0].size()-1, 0, board.size()-1));

    while (!q.empty()) {
      State* s = q.front();
      q.pop();
      if (s->k < goal)
        continue;
      if (s->u > s->d || s->l > s->r || s->u >= board.size() || s->d < 0 || s->l >= board[0].size() || s->r < 0)
        continue;

      if (s->k == goal) {
        return s->m;
      }

      int l, r, u, d;
      l = r = u = d = 0;
      for (int i = s->l; i <= s->r; ++i) {
        if (board[s->u][i] == 'o') ++u;
        if (board[s->d][i] == 'o') ++d;
      }
      for (int i = s->u; i <= s->d; ++i) {
        if (board[i][s->l] == 'o') ++l;
        if (board[i][s->r] == 'o') ++r;
      }
      cout << s->k << "*****"<<s->l << " " << s->r << " " << s->u << " " << s->d << endl;
      cout << l << " " << r << " " << u << " " << d << endl;


      q.push(new State(s->m + s->el + 1, s->k - l, 0, s->er + s->el + 1, s->eu, s->ed, s->l + s->el + 1, s->r, s->u, s->d)); //l
      q.push(new State(s->m + s->er + 1, s->k - r, s->el + s->er + 1, 0, s->eu, s->ed, s->l, s->r - s->er - 1, s->u, s->d)); //r
      q.push(new State(s->m + s->eu + 1, s->k - u, s->el, s->er, 0, s->ed + s->eu + 1, s->l, s->r, s->u + s->eu + 1, s->d)); //u
      q.push(new State(s->m + s->ed + 1, s->k - d, s->el, s->er, s->eu + s->ed + 1, 0, s->l, s->r, s->u, s->d - s->ed - 1)); //d
    }
    return -1;
  }

  int getMinimum(vector <string> board, int K) {
    int k = 0;
    this->board = board;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'o') ++k;
      }
    }
    return solve(k, K);
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o.."
,"oooo"
,"..o."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 3; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...."
,".oo."
,".oo."
,"...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 4; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 6; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DropCoins ___test;
	___test.run_test(-1);
}
// END CUT HERE
