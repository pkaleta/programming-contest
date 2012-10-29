import sys
sys.setrecursionlimit(100000)

def merge(left, right, g, count):
    global s
#    print "merge"
    result = []
    while len(left) > 0 and len(right) > 0:
        if s[0] == '1':
            g[left[0]].append(right[0])
            count[right[0]] += 1
            result.append(left[0])
            left = left[1:]
        else:
            g[right[0]].append(left[0])
            count[left[0]] += 1
            result.append(right[0])
            right = right[1:]
        s = s[1:]
    result.extend(left)
    result.extend(right)
    return result

def solve(a, g, count):
#    print a
    n = len(a)
    if n <= 1:
        return a
    m = n // 2
    left = solve(a[:m], g, count)
    right = solve(a[m:], g, count)
    return merge(left, right, g, count)

def dfs(v, val, solution, count):
    solution[v] = val
    w = -1
    for u in g[v]:
        count[u] -= 1
        if count[u] == 0:
            w = u
    if w != -1:
        dfs(w, val+1, solution, count)

def checksum(solution):
    result = 1
    for i in xrange(len(solution)):
        result = (31 * result + solution[i]) % 1000003
    return result

T = int(sys.stdin.readline())
s = ''
for t in xrange(T):
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()
    g = [[] for i in xrange(0, n+1)]
    count = [0 for i in xrange(0, n+1)]
    solve([i for i in xrange(1, n+1)], g, count)

    v = -1
    for i in xrange(1, n+1):
        if count[i] == 0:
            v = i
            break
    solution = [-1 for i in xrange(n+1)]
    dfs(v, 1, solution, count);
    print "Case #%d: %d" % (t+1, checksum(solution[1:]))
