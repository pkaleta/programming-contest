#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;
using namespace __gnu_cxx;

struct Node {
  // Node(Node* parent, char c) {
  //   this->parent = parent;
  //   this->c = c;
  // }
  Node() {
    count = -1;
  }

  // Node* parent;
  // char c;
  int count;
  map<char, Node*> children;
};

Node* root = new Node();
int n;
string w;
map<string, Node*> t;

void attach(string& prefix, string& suffix, Node* prev) {
  for (int i = 0; i < suffix.size(); ++i) {
    Node* cur = new Node();
    prev->children[suffix[i]] = cur;
    prefix += suffix[i];
    //    cout << "attach: " << prefix << endl;
    t[prefix] = cur;
    prev = cur;
  }
}

string bs(int l, int r, string& s) {
  //  cout << l << " " << r << endl;
  if (l == r) {
    //    cout << "*********" << s.substr(0, l) << endl;
    return s.substr(0, l);
  }
  if (l + 1 == r) {
    if (t.find(s.substr(0, r)) != t.end()) {
      //      cout << "*********" << s.substr(0, r) << endl;
      return s.substr(0, r);
    }
    //    cout << "*********" << s.substr(0, l) << endl;
    return s.substr(0, l);
  }

  int m = (l + r) / 2;
  if (t.find(s.substr(0, m)) != t.end())
    return bs(m, r, s);
  else
    return bs(l, m, s);
}

void add(string w) {
  Node* cur = root;
  int i = 0;

  // while (cur->children.find(w[i]) != cur->children.end())
  //   cur = cur->children[w[i++]];
  string prefix = bs(0, w.size(), w);
  string suffix = w.substr(prefix.size(), w.size());
  //  cout << "######" << prefix << " " << suffix << endl;
  attach(prefix, suffix, t[prefix]);
}

int updateCounts(Node* node) {
  if (node->count != -1) return node->count;

  if (node->children.size() == 0) {
    node->count = 0;
    return 0;
  }

  int ret = 0;
  for (map<char, Node*>::iterator i = node->children.begin(); i != node->children.end(); ++i)
    ret += 1 + updateCounts(i->second);
  node->count = ret;
  return ret;
}

string find(int k, Node* cur, string ret) {
  int total = 0;
  if (cur == NULL) return "INVALID";
  if (k == 0) return ret;
  map<char, Node*> children = cur->children;
  //for (set<char>::iterator i = cur->childNames.begin(); i != cur->childNames.end(); ++i) {
  for (char c = 'a'; c <= 'z'; ++c) {
    if (children.find(c) != children.end()) {
      int count = children[c]->count;
      if (total + count + 1 >= k)
        return find(k - total - 1, children[c], ret + c);
      else
        total += count + 1;
    }
  }
  return "INVALID";
}

// string buildWord(Node* n) {
//   string s = "";
//   while (n != root) {
//     s = s + n->c;
//     n = n->parent;
//   }
//   reverse(s.begin(), s.end());
//   return s;
// }

int main() {
  int k, q;
  t[""] = root;

  cin >> n;
  while (n--) {
    cin >> w;
    for (int i = 0; i < w.size(); ++i) {
      string substr = w.substr(i, w.size()-i);
      //      cout << "adding: " << substr << endl;
      add(substr);
    }
  }
  updateCounts(root);
  cin >> q;
  while (q--) {
    cin >> k;
    // if (pos[k])
    //     //    if (pos.find(k) != pos.end())
    //   cout << buildWord(pos[k]) << endl;
    // else
    //   cout << "INVALID" << endl;
    if (k > root->count)
      cout << "INVALID" << endl;
    else {
      string ret = find(k, root, "");
      cout << ret << endl;
    }
  }
  return 0;
}
