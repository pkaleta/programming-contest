#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

class Node {
    public:
        Node() {}
        Node(char c) : value(c) {}

        char phase;
        bool changed;
        char value;
        Node* nodes[4];
};

char* read(char* s, Node* node) {
    //printf("********* %s\n", s);
    node->value = *s;
    node->phase = 0;
    node->changed = false;
    if (*s == 'S') {
        for (int i = 0; i < 4; ++i) {
            node->nodes[i] = new Node();
            s = read(s + 1, node->nodes[i]);
        }
    }
    return s;
}

void dfs(Node* node) {
    int flag = true;

    for (int i = 0; i < 4; ++i) {
        if (node->nodes[i]->value == 'S') {
            dfs(node->nodes[i]);
        }
        if (i && (node->nodes[i]->value != node->nodes[i-1]->value)) {
            flag = false;
        }
        node->phase = max(node->phase, node->nodes[i]->phase);
    }
    if (flag) {
        node->phase ++;
        node->changed = true;
        node->value = node->nodes[0]->value;
    }
}

void print(Node* node) {
    //printf("%c", node->value);
    printf("******************** adres: %lld, *** lit: %c\n", node, node->value);
    if (node->value == 'S') {
        for (int i = 0; i < 4; ++i) {
            print(node->nodes[i]);
        }
    }
}

void clean(Node* node) {
    printf("*** adres: %lld, *************** %c\n", node, node->value);
    if (node->value == 'S' || node->changed) {
        for (int i = 0; i < 4; ++i) {
            clean(node->nodes[i]);
        }
        delete node;
    }
}

int main() {
    int t;
    char s[MAXN];

    scanf("%d\n", &t);
    Node* node;
    printf("*********** size: %d\n", sizeof(Node));
    while (t--) {
        scanf("%s", s);

        node = new Node();
        read(s, node);

        if (*s == 'S')
            dfs(node);
        int result = 0;
        print(node);
        printf(" %d\n", node->phase + 1);
        clean(node);
    }
    return 0;
}
