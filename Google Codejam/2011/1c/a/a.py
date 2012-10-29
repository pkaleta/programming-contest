import sys

T = int(sys.stdin.readline())

def check(m, R, C):
    for r in xrange(R):
        for c in xrange(C):
            if m[r][c] == '#':
                if r < R-1 and c < C-1 and m[r][c+1] == '#' and m[r+1][c] == '#' and m[r+1][c+1] == '#':
                    m[r][c] = '/'
                    m[r][c+1] ='\\'
                    m[r+1][c] ='\\'
                    m[r+1][c+1] = '/'
                else:
                    return False
    return True

for t in xrange(T):
    m = []
    R, C = map(int, sys.stdin.readline().split())

    for r in xrange(R):
        line = list(sys.stdin.readline()[:-1])
        m.append(line)

    print "Case #%d:" % (t+1)
    if check(m, R, C):
        for r in xrange(R):
            print ''.join(m[r])
    else:
        print "Impossible"


