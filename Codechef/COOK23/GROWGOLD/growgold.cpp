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

const long long MOD = 100000007LL;

int T;
long long initTax, slot1, slot2, N, K;

int main() {
  long long tax[200];
  cin >> T;

  while (T--) {
    cin >> initTax >> slot1 >> slot2 >> K >> N;
    memset(tax, 0, sizeof(tax));

    long long total_tax = initTax;
    tax[0] = initTax;
    for (int i = 0; i < slot1; ++i) {
      tax[i + 1] = tax[i] + 1;
      total_tax += tax[i] + 1;
    }
    for (int i = 0; i < slot2; ++i) {
      tax[i + 1 + slot1] = 2 * tax[i + slot1];
      total_tax += 2 * tax[i + slot1];
    }

    list<long long> l;
    for (int i = 0; i < K; ++i) {
      l.push_front(tax[slot1 + slot2 - i]);
    }

    for (int i = 0; i < N - (slot1 + slot2); ++i) {
      
    }

    for (int i = 0; i <= slot1 + slot2; ++i) {
      cout << tax[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
