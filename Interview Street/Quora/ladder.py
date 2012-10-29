import sys
from copy import copy
from collections import defaultdict

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

words = filter(lambda w: len(w) == n, map(lambda w: w.strip().lower(), sys.stdin.readlines()[:k]))

def diffs(w1, w2):
    return reduce(lambda acc, i: acc+1 if w1[i] != w2[i] else acc, xrange(len(w1)), 0)

cost = {}

def set_cost(chars, cst):
    for c in chars:
        cost[c] = cst

set_cost(('a', 'e', 'i', 'l', 'n', 'o', 'r', 's', 't', 'u'), 1)
set_cost(('d', 'g'), 2)
set_cost(('b', 'c', 'm', 'p'), 3)
set_cost(('f', 'h', 'v', 'w', 'y'), 4)
set_cost(('k'), 5)
set_cost(('j', 'x'), 8)
set_cost(('q','z'), 10)

def calc_score(w):
    return reduce(lambda acc, l: acc + cost[l], w, 0)

scores = [calc_score(w) for w in words]
words = zip(words, scores)
edges = {}
nwords = len(words)
inlevel = [0 for i in xrange(nwords)]

for i in xrange(nwords):
    edges[i] = []
    w1, s1 = words[i]
    for j in xrange(nwords):
        w2, s2 = words[j]
        if s1 > s2 and diffs(w1, w2) == 1:
            edges[i].append(j)
            inlevel[j] += 1

paths = defaultdict(list)
visited = []

def path_cost(path):
    ret = 0
#    print "***", path
    for e in path:
        ret += scores[e]
    return ret

def dfs(v, path):
    paths[len(path)].append((path_cost(path), tuple(path)))
    for u in edges[v]:
        np = copy(path)
        np.append(u)
        dfs(u, np)

#print edges
max_result = 0
for v in xrange(nwords):
    max_result = max(max_result, scores[v])
    if inlevel[v] > 0:
        continue
    paths = defaultdict(list)
    dfs(v, [])
#    print words[v], paths
    for l, ps in paths.items():
        for i in xrange(len(ps)):
            c1, p1 = ps[i]
            sp1 = set(p1)
            for j in xrange(i, len(ps)):
                c2, p2 = ps[j]
                possible_best = scores[v] + c1 + c2
                if possible_best > max_result:
                    sp2 = set(p2)
                    if p1 != p2 and len(sp1.intersection(sp2)) == 0:
                        max_result = max(max_result, possible_best)

print max_result
