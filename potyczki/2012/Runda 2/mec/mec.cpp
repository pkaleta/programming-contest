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
#include<tr1/unordered_map>


using namespace std;

const int MAX_N = 40005;
const int MAX_M = 55;


string team2str(vector<int> team) {
  string s;
  ostringstream ss;

  for (int i = 0; i < team.size(); ++i)
    ss << team[i] << "*";

  return ss.str();
}


int main() {
  int n, m;
  int player;
  vector<int> teams[MAX_N];

  scanf("%d%d", &n, &m);
  int team_size = (int)(n / 2);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &player);
      int opponent = j >= team_size;
      teams[player].push_back(2 * i + opponent);
    }
  }

  set<string> seen;
  string* team_strs[MAX_N];

  for (int i = 1; i <= n; ++i)
    team_strs[i] = NULL;

  bool found = false;

  for (int i = 1; i <= n; ++i) {
    string s = team2str(teams[i]);

    if (seen.find(s) != seen.end()) {
      found = true;
      break;
    }
    else
      seen.insert(s);
  }

  if (found)
    printf("NIE\n");
  else
    printf("TAK\n");

  return 0;
}
