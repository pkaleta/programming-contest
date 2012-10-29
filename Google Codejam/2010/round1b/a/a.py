import sys

ts = int(sys.stdin.readline())

for t in xrange(ts):
    root = {}

    n, m = map(int, sys.stdin.readline().split())
    for i in xrange(n):
        dir = sys.stdin.readline()
        dirs = dir[:-1].split("/")
        cur = root
        for j in xrange(len(dirs)):
            if (dirs[j] != ""):
                if not cur.has_key(dirs[j]):
                    cur[dirs[j]] = {}
                cur = cur[dirs[j]]

    result = 0
    for i in xrange(m):
        dir = sys.stdin.readline()
        dirs = dir[:-1].split("/")
        cur = root
        for j in xrange(len(dirs)):
            if (dirs[j] != ""):
                if not cur.has_key(dirs[j]):
                    cur[dirs[j]] = {}
                    result += 1
                cur = cur[dirs[j]]

    print "Case #%d: %d" % (t+1, result)
