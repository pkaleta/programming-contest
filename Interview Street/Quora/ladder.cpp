#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, k;
vector<string> words;
int costs[256];
vector<int> scores;
vector<vector<int> > edges;
vector<int> inlevel;

int diffs(string& s1, string& s2) {
  int ret = 0;
  for (int i = 0; i < s1.size(); ++i)
    ret += s1[i] != s2[i];
  return ret;
}

void set_cost(string s, int cost) {
  for (int i = 0; i < s.size(); ++i)
    costs[s[i]] = cost;
}

void set_costs() {
  set_cost("aeilnorstu", 1);
  set_cost("dg", 2);
  set_cost("bcmp", 3);
  set_cost("fhvwy", 4);
  set_cost("k", 5);
  set_cost("jx", 8);
  set_cost("qz", 10);
}

int calc_score(string& w) {
  int ret = 0;
  for (int i = 0; i < w.size(); ++i)
    ret += costs[w[i]];
  return ret;
}

void calc_graph() {
  for (int i = 0; i < words.size(); ++i) {
    inlevel.push_back(0);
    edges.push_back(vector<int>());
  }
  //  cout << "****" << endl;

  for (int i = 0; i < words.size(); ++i) {
    string w1 = words[i];
    int s1 = scores[i];
    for (int j = 0; j < words.size(); ++j) {
      string w2 = words[j];
      int s2 = scores[j];

      if (s1 > s2 && diffs(w1, w2) == 1) {
        //        cout << i << "->" << j << endl;
        edges[i].push_back(j);
        //        cout << "######" << edges[i].size() << endl;
        inlevel[j] += 1;
      }
    }
  }
  //  cout << "finisz" << endl;
}

int path_cost(vector<int> path) {
  int ret = 0;
  for (int i = 0; i < path.size(); ++i)
    ret += scores[path[i]];
  return ret;
}

map<int, vector<vector<int> > > paths;

void dfs(int v, vector<int> path) {
  // cout << "adding: " << v << " " << edges[v].size() << endl;
  // for (int i = 0; i < path.size(); ++i) {
  //   cout << path[i] << endl;
  // }
  if (paths.find(path.size()) == paths.end())
    paths[paths.size()] = vector<vector<int> >();
  paths[path.size()].push_back(path);
  for (int i = 0; i < edges[v].size(); ++i) {
    vector<int> np(path);
    np.push_back(edges[v][i]);
    dfs(edges[v][i], np);
  }
}

int find_max() {
  int max_result = 0;
  //  cout << "*******" << endl;
  for (int v = 0; v < words.size(); ++v) {
    max_result = max(max_result, scores[v]);
    if (inlevel[v] > 0) continue;
    paths.clear();
    //    cout << "wierzcholek: " << v << " " << words[v] << endl;
    dfs(v, vector<int>());
    for (map<int, vector<vector<int> > >::iterator k = paths.begin(); k != paths.end(); ++k) {
      int len = k->first;
      vector<vector<int> > ps = k->second;
      //      cout << len << ": " << endl;
      // for (int z = 0; z < ps.size(); ++z) {
      //   for (int x = 0; x < ps[z].size(); ++x) {
      //     cout << words[ps[z][x]] << " ";
      //   }
      //   cout << endl;
      // }
      // cout << "########" << endl;
      for (int i = 0; i < ps.size(); ++i) {
        for (int j = i+1; j < ps.size(); ++j) {
          //          cout << "##############" << words[ps[j][0]] << " " << path_cost(ps[j]) << endl;
          int possible_best = scores[v] + path_cost(ps[i]) + path_cost(ps[j]);
          //          cout << i << " " << j << " @" << possible_best << endl;
          if (possible_best > max_result) {
            vector<int> inter(ps[i].size());
            vector<int>::iterator it;
            it = set_intersection(ps[i].begin(), ps[i].end(), ps[j].begin(), ps[j].end(), inter.begin());
            //            cout << "@@" << it-inter.begin() << endl;
            if (ps[i] != ps[j] && (it - inter.begin()) == 0) {
              max_result = max(max_result, possible_best);
            }
          }
        }
      }
    }
  }
  return max_result;
}

int main() {
  string w;
  set_costs();
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> w;
    if (w.size() == n) {
      std::transform(w.begin(), w.end(), w.begin(), ::tolower);
      words.push_back(w);
      scores.push_back(calc_score(w));
    }
  }
  calc_graph();
  cout << find_max() << endl;
  return 0;
}
