import sys

T = int(sys.stdin.readline())

for t in xrange(T):
    print "Case #%d: " % (t+1)
    N = int(sys.stdin.readline())
    s = []
    wp = [0.0 for i in xrange(N)]
    owp = [0.0 for i in xrange(N)]
    oowp = [0.0 for i in xrange(N)]
    games = [0 for i in xrange(N)]

    for i in xrange(N):
        line = sys.stdin.readline()[:-1]
        s.append(line)

#    print s

    for i in xrange(N):
#        print "druzyna A: %d" % i
        wins = 0
        for j in xrange(N):
            if s[i][j] != '.':
                games[i] += 1
            if s[i][j] == '1':
                wp[i] += 1

        wp[i] = float(wp[i]) / float(games[i])

        for j in xrange(N):
            if i != j:
#                print "druzyna B: %d" % j
                ws = 0
                gs = 0
                if s[i][j] != '.':
                    for k in xrange(N):
#                        print "K: %d" % k
                        if k != i and k != j:
#                            print "druzyna C: %d" % k
                            if s[j][k] != '.':
                                gs += 1
                            if s[j][k] == '1':
                                ws += 1

                    owp[i] += float(ws) / float(gs)
        owp[i] /= float(games[i])

    for i in xrange(N):
        for j in xrange(N):
            if i != j:
                if s[i][j] != '.':
#                    print "druzyna B: %d %f" % (j, owp[j])
                    oowp[i] += owp[j]
        oowp[i] /= float(games[i])

#        print wp[i], owp[i], oowp[i]

        rpi = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]

        print rpi

