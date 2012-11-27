#include <cstdio>
#include <iostream>


using namespace std;

const int MAX_SIZE = 100;

int p[MAX_SIZE][MAX_SIZE];

int main() {
  int n, x1, y1, x2, y2;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int y = y1; y < y2; ++y) {
      for (int x = x1; x < x2; ++x) {
        p[y][x] += 1;
      }
    }
  }

  int total = 0;

  for (int y = MAX_SIZE - 1; y >= 0; --y) {
    for (int x = 0; x < MAX_SIZE; ++x) {
      //      cout << p[y][x];
      if (p[y][x] >= n - 1) total += 1;
    }
    //    cout << endl;
  }

  cout << total << endl;

  return 0;
}
