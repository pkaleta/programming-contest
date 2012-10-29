import sys


def dfs(i, visited, g):
    indexes = []
    visited.add(i)
    for j in g[i]:
        if j not in visited:
            indexes.extend(dfs(j, visited, g))
    indexes.append(i)
    return indexes


def solve(K, p, g):
    visited = set()
    result = [0 for i in xrange(K)]
    for i in xrange(K):
        if i not in visited:
            indexes = dfs(i, visited, g)
            values = [p[i] for i in indexes]

            indexes = sorted(indexes)
            values = sorted(values)

            for j in xrange(len(indexes)):
                result[indexes[j]] = values[j]

    return result


if __name__ == "__main__":
    K = int(sys.stdin.readline())
    p = map(int, sys.stdin.readline().split())
    g = []
    for i in xrange(K):
        line = sys.stdin.readline().strip()
        g.append([j for j in xrange(K) if line[j] == "Y"])

    result = solve(K, p, g)
    print " ".join(map(str, result))
