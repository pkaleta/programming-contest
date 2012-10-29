#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const long long MAXN = 500000;
const long long INF = 999999999;

struct Node {
  Node(long long left, long long right) {
    this->left = left;
    this->right = right;
    this->weight = 0;
  }

  long long left;
  long long right;
  long long weight;
};

Node* t[MAXN];
vector<pair<long long, long long> > a;
vector<long long> x;
vector<long long> w;
long long n;


void initialize(long long i, long long l, long long r) {
  //  cout << "****" << i << " " << x[l] << " " << x[r-1] << "(" << l << "," << r << ")" << endl;
  t[i] = new Node(x[l], x[r]);
  if (l + 1 < r) {
    long long m = (l + r) / 2;
    initialize(2 * i, l, m);
    initialize(2 * i + 1, m, r);
  }
}

long long query(long long i, long long x) {
  //cout << "query: " << t[i]->left << ", " << t[i]->right << " " << x << endl;
  if (t[i]->right != x) {
    if (x > t[2 * i]->right) {
      return max(t[2 * i]->weight, query(2 * i + 1, x));
    } else {
      return query(2 * i, x);
    }
  } else {
    //cout << "found: " << t[i]->weight << endl;
    return t[i]->weight;
  }
}

void insert(long long i, long long x, long long weight) {
  //cout << "insert *** " << t[i]->left << ", " << t[i]->right << " " << x << " " << weight << endl;
  t[i]->weight = max(t[i]->weight, weight);
  //cout << "####" << 2 * i << endl;
  if (t[2 * i]) {
    //cout << "*******" << endl;
    if (x >= t[2 * i + 1]->left) {
      insert(2 * i + 1, x, weight);
    } else {
      insert(2 * i, x, weight);
    }
  }
}

int main() {
  long long T;
  long long tmp;
  cin >> T;

  while (T--) {
    cin >> n;
    x.clear();
    w.clear();
    a = vector<pair<long long, long long> >(MAXN);
    for (long long i = 0; i < MAXN; ++i)
      a[i] = make_pair(INF, 0);
    for (long long i = 0; i < n; ++i) {
      cin >> tmp;
      x.push_back(tmp);
    }
    for (long long i = 0; i < n; ++i) {
      cin >> tmp;
      w.push_back(tmp);
    }
    for (long long i = 0; i < n; ++i) {
      a[i] = make_pair(x[i], w[i]);
    }

    sort(x.begin(), x.end());
    vector<long long>::iterator it = unique(x.begin(), x.end());
    x.resize(it - x.begin());
    x.push_back(0);
    long long p = (long long)(ceil(log2(x.size()+1)));
    //cout << "###" << p << endl;
    while (x.size() < (1 << p)) {
      x.push_back(INF);
    }
    x.push_back(INF);
    sort(x.begin(), x.end());
    //cout << "##########" << x.size() << endl;
    // for (long long i = 0; i < x.size(); ++i) {
    //   cout << x[i] << " ";
    // }
    //cout << endl;

    initialize(1, 0, 1 << p);
    //cout << "**********" << endl;
    //cout << t[2]->left << " " << t[2]->right << endl;

    for (long long i = 0; i < n; ++i) {
      long long w = query(1, a[i].first);
      //cout << "inserting: " << a[i].first << ", " << w + a[i].second << endl;
      insert(1, a[i].first, w + a[i].second);
    }
    cout << t[1]->weight << endl;
  }
  return 0;
}
