#include <cstdio>
#include <list>

const int MAXN = 100005;

using namespace std;

class Node;

class Edge {
    public:
        Edge(int v, int n, Node* nd) : value(v), nodes(n), node(nd) { }

        int value;
        int nodes;
        Node* node;
};

class Node {
    public:
        Node(int n) : num(n) {}

        int num;
        list<Edge*> edges;
};

Node* nodes[MAXN];

void dfs(Node* prev, Edge* edge) {
    Node* cur = edge->node;
    printf("****** jestem w: %d\n", cur->num);
    list<Edge*>::iterator e;
    for (e = cur->edges.begin(); e!= cur->edges.end(); ++e) {
        edge->value += 1;
        if (prev != (*e)->node) {
            dfs(cur, (*e));
            edge->nodes += (*e)->nodes;
            edge->value += (*e)->value;
        }
    }
}

void dfs2(Node* prev, Edge* edge, int nodes, int value, int& min_node, int& min_result) {
    Node* cur = edge->node;
    int r = 1 + value + nodes;
    list<Edge*>::iterator e;
    for (e = cur->edges.begin(); e != cur->edges.end(); ++e) {
        if (prev != (*e)->node) {
            r += (*e)->value;
        }
    }
    printf("*********** node: %d, result: %d\n", cur->num, r);
    if (r < min_result || min_result == -1) {
        min_result = r;
        min_node = cur->num;
    }

    for (e = cur->edges.begin(); e != cur->edges.end(); ++e) {
        if (prev != (*e)->node) {
            dfs2(cur, (*e), nodes + 1, r, min_node, min_result);
        }
    }
}

int main() {
    int c, n, p;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            nodes[i] = new Node(i);
        }

        for (int i = 2; i <= n; ++i) {
            scanf("%d", &p);
            Edge* edge = new Edge(0, 1, nodes[p]);
            nodes[i]->edges.push_back(edge);
            edge = new Edge(0, 1, nodes[i]);
            nodes[p]->edges.push_back(edge);
        }

        list<Edge*>::iterator e;
        for (e = nodes[1]->edges.begin(); e != nodes[1]->edges.end(); ++e) {
            dfs(nodes[1], (*e));
        }

        for (int i = 1; i <= n; ++i) {
            list<Edge*>::iterator e;
            for (e = nodes[i]->edges.begin(); e != nodes[i]->edges.end(); ++e) {
                printf("**** %d->%d, value: %d, nodes: %d\n", i, (*e)->node->num, (*e)->value, (*e)->nodes);
            }
        }

        int min_node = -1;
        int min_value = -1;

        for (e = nodes[1]->edges.begin(); e != nodes[1]->edges.end(); ++e) {
            dfs2(nodes[1], (*e), (*e)->nodes, (*e)->value, min_node, min_value);
        }
        printf("%d %d\n", min_node, min_value);
    }
    return 0;
}
