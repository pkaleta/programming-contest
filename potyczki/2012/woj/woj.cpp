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


const int MAX_N = 1000005;
const int JAS = true;
const int STAS = false;
const int NONE = -1;


struct Tree {
  Tree* left;
  Tree* right;
  int person;
  int number;

  Tree(int p, int n, Tree* l, Tree* r) : person(p), number(n), left(l), right(r) {}
};


void read_cards(int n, int person, queue<Tree*>& q) {
  int number;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &number);
    Tree* t = new Tree(NONE, number, NULL, NULL);
    q.push(t);
  }
}


int calc_score(Tree* tree, int person) {
  if (tree->person == NONE)
    return tree->number;

  int l = calc_score(tree->left, person);
  int r = calc_score(tree->right, person);
  if (person == tree->person)
    return max(l, r);
  else
    return min(l, r);
}


int main() {
  int n;
  int number;
  queue<Tree*> j;
  queue<Tree*> s;

  scanf("%d", &n);
  read_cards(n, JAS, j);
  read_cards(n, STAS, s);

  while (j.size() > 1) {
    Tree* tj1 = j.front();
    j.pop();
    Tree* tj2 = j.front();
    j.pop();
    Tree* tj = new Tree(JAS, NULL, tj1, tj2);

    Tree* ts1 = s.front();
    s.pop();
    Tree* ts2 = s.front();
    s.pop();
    Tree* ts = new Tree(STAS, NULL, ts1, ts2);

    j.push(ts);
    s.push(tj);
  }

  Tree* tj = j.front();
  Tree* ts = s.front();
  int j_score = calc_score(tj, JAS);
  int s_score = calc_score(ts, STAS);
  printf("%d\n", j_score - s_score);

  return 0;
}
