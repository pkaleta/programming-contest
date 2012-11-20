#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#include <cstring>

using namespace std;


int check(int a, int b, int k) {
  int v_count = (int)(a / k);
  if (2 * k > b) return v_count;

  int total = 2 * v_count;

  int h_count = (int)((b - (2 * k)) / k);
  if (2 * k > a)
    total += h_count;
  else
    total += 2 * h_count;

  return total;
}


int main() {
  int A, B, K;
  scanf("%d%d%d", &A, &B, &K);

  if (A > B) swap(A, B);

  if (K > A) {
    printf("0\n");
    return 0;
  }

  printf("%d\n", max(check(A, B, K), check(B, A, K)));

  return 0;
}
