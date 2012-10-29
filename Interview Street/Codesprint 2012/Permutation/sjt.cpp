#include <cstdio>
#include <vector>

using namespace std;

int N;
int p[100], pi[100];   /* The permutation and its inverse */
int dir[100];          /* The directions of each element  */
vector<int> bestp;
vector<vector<int> > v;
int bestc = 0;
int curc = 0;
const int LIMIT = 28000000;
int reps = 0;

// void PrintPerm() {
//   for (int i=1; i <= N; ++i) {
//     printf( "%d", p[i] );
//   }
// }

// void PrintTrans(int x, int y) {
//   printf( "    (%d %d)", x, y );  printf( "\n" );
// }

void Move(int x, int d) {
  //  PrintTrans( pi[x], pi[x]+d);
  int i = min(pi[x], pi[x]+d);
  int j = max(pi[x], pi[x]+d);

  if (N == 2) {
    curc = v[p[j]][p[i]];
  } else if (i == 1) {
    curc = curc - v[p[i]][p[j]] - v[p[j]][p[j+1]] + v[p[j]][p[i]] + v[p[i]][p[j+1]];
  } else if (j == N) {
    curc = curc - v[p[i]][p[j]] - v[p[i-1]][p[i]] + v[p[i-1]][p[j]] + v[p[j]][p[i]];
  } else {
    curc = curc - v[p[i-1]][p[i]] - v[p[i]][p[j]] - v[p[j]][p[j+1]] + v[p[i-1]][p[j]] + v[p[j]][p[i]] + v[p[i]][p[j+1]];
  }

  int z = p[pi[x]+d];
  p[pi[x]] = z;
  p[pi[x]+d] = x;
  pi[z] = pi[x];
  pi[x] = pi[x]+d;

  // printf("******** %d\n", curc);
  // PrintPerm();
  //printf("***** %d\n", 10000);
  if (reps >= LIMIT)
    return;
  else
    ++reps;
  if (curc > bestc) {
    bestc = curc;
    bestp = vector<int>(p + 1, p + N + 1);
  }
}

void Perm (int n) {
  if (n <= N) {
    Perm(n+1);
    for (int i=1; i<=n-1; ++i) {
       Move(n, dir[n]);
       if (reps >= LIMIT)
         return;
       Perm(n+1);
    }
    dir[n] = -dir[n];
  }
} /* of Perm */;

int main() {
  int x;
  scanf("%d", &N);
  v.push_back(vector<int>());
  for (int i = 0; i <= N; ++i)
    v[0].push_back(0);
  for (int i = 0; i < N; ++i) {
    vector<int> line;
    line.push_back(0);
    for (int j = 0; j < N; ++j) {
      scanf("%d", &x);
      line.push_back(x);
    }
    v.push_back(line);
  }

  for (int i=1; i <= N; ++i) {
    dir[i] = -1;  p[i] = i;  pi[i] = i;
    bestp.push_back(i);
  }

  for (int i = 0; i < N-1; ++i) {
    bestc += v[bestp[i]][bestp[i+1]];
  }
  curc = bestc;

  //  printf("######### %d\n", bestc);

  Perm(1);
  //  printf("\n");
  // for (int i = 0; i < n; ++i)
  //   p.push_back(i);
  // int reps = 0;
  // while (next_permutation(p.begin(), p.end()) && reps <= 3000000) {
  //   int count = 0;
  //   for (int i = 0; i < n-1; ++i)
  //     count += v[p[i]][p[i+1]];
  //   if (count > bestc) {
  //     bestc = count;
  //     bestp = p;
  //   }
  //   ++reps;
  // }
  for (int i = 0; i < N; ++i)
    printf("%d ", bestp[i]-1);
  printf("\n");
  return 0;
}
