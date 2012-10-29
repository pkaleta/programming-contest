#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long n, x;
  cin >> n;
  set<pair<long long, long long> > q;
  long long id = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> x;
    q.insert(make_pair(x, id++));
  }

  long long ret = 0;
  if (q.size() == 1) {
    cout << (*q.begin()).first << endl;
    return 0;
  }
  while (q.size() > 1) {
    pair<long long, long long> a = *q.begin();
    q.erase(q.begin());
    pair<long long, long long > b = *q.begin();
    q.erase(q.begin());

    long long x = a.first + b.first;
    ret += x;
    q.insert(make_pair(x, id++));
  }
  cout << ret << endl;
  return 0;
}
