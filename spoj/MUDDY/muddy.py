import numpy as np
from collections import defaultdict
from collections import deque


class Graph(object):
    def __init__(self):
        self.edges = defaultdict(set)
        self.U = set()
        self.V = set()
        self.vertices = set()

    def add_edge(self, u, v):
        self.vertices.add(u)
        self.vertices.add(v)
        self.edges[u].add(v)
        self.edges[v].add(u)
        self.U.add(u)
        self.V.add(v)


def create_graph(R, C, field):
    cur_vertex = 1
    h_vertices = np.zeros((R, C))
    v_vertices = np.zeros((R, C))

    for i in xrange(R):
        if i > 0 and field[i - 1][C - 1] == 1:
            cur_vertex += 1

        if field[i][0] == 1:
            h_vertices[i][0] = cur_vertex

        for j in xrange(1, C):
            if field[i][j - 1] == 1 and field[i][j] == 0:
                cur_vertex += 1
            if field[i][j] == 1:
                h_vertices[i][j] = cur_vertex

    cur_vertex += 1

    for j in xrange(C):
        if j > 0 and field[R - 1][j - 1] == 1:
            cur_vertex += 1

        if field[0][j] == 1:
            v_vertices[0][j] = cur_vertex

        for i in xrange(1, R):
            if field[i - 1][j] == 1 and field[i][j] == 0:
                cur_vertex += 1
            if field[i][j] == 1:
                v_vertices[i][j] = cur_vertex

    # print h_vertices
    # print v_vertices

    G = Graph()

    for i in xrange(R):
        for j in xrange(C):
            if h_vertices[i][j] > 0 and v_vertices[i][j] > 0:
                u = int(h_vertices[i][j]) - 1
                v = int(v_vertices[i][j]) - 1
                G.add_edge(u, v)

    return G


class HopcroftKarp(object):
    INFINITY = float("inf")

    def __init__(self, G):
        self.G = G

    def match(self):
        self.pair = {}
        self.dist = {}
        self.q = deque()

        for v in self.G.vertices:
            self.pair[v] = None
            self.dist[v] = HopcroftKarp.INFINITY

        matching = 0

        while self.bfs():
            for v in self.G.U:
                if self.pair[v] is None and self.dfs(v):
                    matching = matching + 1

        return matching

    def dfs(self, v):
        if v is not None:
            for u in self.G.edges[v]:
                if (self.dist[self.pair[u]] == self.dist[v] + 1 and
                        self.dfs(self.pair[u])):
                    self.pair[u] = v
                    self.pair[v] = u

                    return True

            self.dist[v] = HopcroftKarp.INFINITY
            return False

        return True

    def bfs(self):
        for v in self.G.U:
            if self.pair[v] is None:
                self.dist[v] = 0
                self.q.append(v)
            else:
                self.dist[v] = HopcroftKarp.INFINITY

        self.dist[None] = HopcroftKarp.INFINITY

        while len(self.q) > 0:
            v = self.q.pop()
            if v is not None:
                for u in self.G.edges[v]:
                    if self.dist[self.pair[u]] == HopcroftKarp.INFINITY:
                        self.dist[self.pair[u]] = self.dist[v] + 1
                        self.q.append(self.pair[u])

        return self.dist[None] != HopcroftKarp.INFINITY


def solve(R, C, field):
    return HopcroftKarp(create_graph(R, C, field)).match()


#if __name__ == "__main__":
T = int(raw_input())
ch2num = {"*": 1, ".": 0}

for t in xrange(T):
    field = []
    R, C = map(int, raw_input().split())
    for i in xrange(R):
        field.append(map(lambda c: ch2num[c], list(raw_input().strip())))

    print solve(R, C, field)
