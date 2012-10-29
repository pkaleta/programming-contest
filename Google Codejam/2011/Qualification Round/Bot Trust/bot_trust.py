import sys
from copy import copy

ts = int(sys.stdin.readline())

def other(c):
    if c == 'O':
        return 'B'
    else:
        return 'O'

for t in xrange(ts):
    result = 0
    pos = {'O' : 1, 'B' : 1}

    line = sys.stdin.readline().split()
    n = int(line[0])
    col = [line[i] for i in xrange(1, 2*n, 2)]
    but = [int(line[i]) for i in xrange(2, 2*n+1, 2)]
    nextPos = [{'O' : -1, 'B' : -1} for i in xrange(n)]

    prev = {'O' : -1, 'B' : -1}
    for i in xrange(n-1, -1, -1):
        nextPos[i] = copy(prev)
        prev[col[i]] = but[i]

    for i in xrange(n):
        time = abs(but[i] - pos[col[i]]) + 1
        result += time
        pos[col[i]] = but[i]

        otherCol = other(col[i])
        otherNextPos = nextPos[i][otherCol]
        otherCurPos = pos[otherCol]
        if otherNextPos > otherCurPos:
            pos[otherCol] = min(otherNextPos, otherCurPos + time)
        else:
            pos[otherCol] = max(otherNextPos, otherCurPos - time)

    print "Case #%d: %d" % (t+1, result)
