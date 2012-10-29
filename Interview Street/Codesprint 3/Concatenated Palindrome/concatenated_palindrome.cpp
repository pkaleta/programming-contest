#include <cstdio>
#include <algorithm>
#include <set>


using namespace std;

const int MAX_N = 105;
const int MAX_M = 100005;

struct Node {
  set<pair<int, int> > word2count;
  Node* children[63];
};

int n, m;
char words[MAX_N][MAX_M];
int prev_counts[MAX_N][MAX_M];
int next_counts[MAX_N][MAX_M];
Node* root;

int to_index(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  } else if (c >= 'a' && c <= 'z') {
    return c - 'a' + 26 + 1;
  } else {
    return c - '0' + 26 + 26 + 1;
  }
}


void initialize() {
  root = new Node();
  for (int i = 0; i < n; ++i) {

    prev_counts[i][0] = 1;
    for (int j = 1; j < m; ++j) {
      if (words[i][j] == words[i][j-1])
        prev_counts[i][j] = prev_counts[i][j-1] + 1;
      else
        prev_counts[i][j] = 1;
    }

    next_counts[i][m-1] = 1;
    for (int j = m-2; j >= 0; --j) {
      if (words[i][j] == words[i][j+1])
        next_counts[i][j] = next_counts[i][j+1] + 1;
      else
        next_counts[i][j] = 1;
    }

    Node* current = root;
    for (int j = m-1; j >= 0; --j) {
      Node * node;
      int index = to_index(words[i][j]);

      if (current->children[index] == NULL) {
        node = new Node();
        current->children[index] = node;
      } else {
        node = current->children[index];
      }
      node->word2count.insert(make_pair(prev_counts[i][j-1], i));
      current = node;
    }
  }
}


// bool is_palin(int i, int start, int stop) {
//   for (int j = start; j < )
// }


int solve() {
  int max_len = 0;

  // for (int i = 0; i < n; ++i) {

  // }

  for (int i = 0; i < n; ++i) {
    //printf("!!!!!!!!!! %s\n", words[i]);
    Node* current = root;
    int j = 0;
    int index = to_index(words[i][j]);

    while (current->children[index] != NULL) {
      //      printf("######## %c\n", words[i][j]);
      current = current->children[index];
      int prev_count = 0;
      int word_index = -1;
      for (set<pair<int, int> >::iterator it = current->word2count.begin(); it != current->word2count.end(); ++it) {
        if (it->second == i)
          continue;

        prev_count = it->first;
        word_index = it->second;
        break;
      }

      if (word_index != -1) {
        //        printf("------ %d %d %d\n", 2 * (j+1), next_counts[i][j+1], prev_count);
        max_len = max(max_len, 2 * (j + 1) + max(next_counts[i][j+1], prev_count));
      } else {
        break;
      }
      index = to_index(words[i][++j]);
    }
  }

  return max_len;
}


int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%s", words[i]);
  }

  initialize();

  // for (int i = 0; i < n; ++i) {
  //   printf("%s\n", words[i]);
  //   for (int j = 0; j < m; ++j) {
  //     printf("%d ", prev_counts[i][j]);
  //   }
  //   printf("\n");
  //   for (int j = 0; j < m; ++j) {
  //     printf("%d ", next_counts[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%d\n", solve());

  return 0;
}
