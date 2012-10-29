import sys

tcs = int(sys.stdin.readline())

for tc in xrange(tcs):
    win = {'B' : False, 'R' : False}
    m = []
    mr = []
    l = sys.stdin.readline()
    n, k = map(int, l.split())
    for i in xrange(n):
        line = sys.stdin.readline()
        m.append(line[:-1])
        mr.append(['.']*n)
    for i in xrange(n):
        for j in xrange(n):
            mr[j][n-i-1] = m[i][j]


    for i in xrange(n-1, -1, -1):
        for j in xrange(n):
            y = i+1
            while y < n and mr[y][j] == '.':
                y = y+1
            tmp = mr[i][j]
            mr[i][j] = '.'
            mr[y-1][j] = tmp

#    print("**********")
##    for i in xrange(n):
##        print m[i]
##
#    for i in xrange(n):
#        print mr[i]


    for i in xrange(n):
        for j in xrange(n):
            flag = True
            for l in xrange(1, k):
                if j+l < n:
                    if mr[i][j+l] != mr[i][j]:
                        flag = False
                        break
                else:
                    flag = False
            if flag:
                win[mr[i][j]] = True

            flag = True
            for l in xrange(1, k):
                if i+l < n:
                    if mr[i+l][j] != mr[i][j]:
                        flag = False
                        break
                else:
                    flag = False

            if flag:
                win[mr[i][j]] = True

            flag = True
            for l in xrange(1, k):
                if i+l < n and j+l < n:
                    if mr[i+l][j+l] != mr[i][j]:
                        flag = False
                        break
                else:
                    flag = False
            if flag:
                win[mr[i][j]] = True

            flag = True
            for l in xrange(1, k):
                if i-l >= 0 and j+l < n:
                    if mr[i-l][j+l] != mr[i][j]:
                        flag = False
                        break
                else:
                    flag = False
            if flag:
                win[mr[i][j]] = True


    if win['B'] and win['R']:
        print "Case #%d: Both" % (tc+1)
    elif win['B']:
        print "Case #%d: Blue" % (tc+1)
    elif win['R']:
        print "Case #%d: Red" % (tc+1)
    else:
        print "Case #%d: Neither" % (tc+1)
