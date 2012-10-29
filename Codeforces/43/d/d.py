import sys

l, b, f = map(int, sys.stdin.readline().split())
n = int(sys.stdin.readline())
p = [(0, l)]

rs = []
dist = [-1 for i in xrange(200)]

for j in xrange(n):
#    print p

    t, x = map(int, sys.stdin.readline().split())
    rs.append((t, x))

    if t == 1:
        if len(p) == 1 and x == l:
            p = []
            dist[j] = 0
        else:
            for i in xrange(len(p)):
                start, stop = p[i]
                if start == 0 and start+x+f <= stop:
                    tmp = start+x+f
                    if tmp == stop:
                        p = [(start+x, start+x+f)] + p[1:]
                    else:
                        p = [(start+x, stop)] + p[1:]
                    dist[j] = start
                    break
                elif stop == l and start+b+x <= stop:
                    tmp = start+b+x
                    if tmp == stop:
                        p = p[:-1] + [(start, start+b)]
                    else:
                        p = p[:-1] + [(start, start+b)] + [(tmp, stop)]
                    dist[j] = start+b
                    break
                elif start+b+x+f <= stop:
                    tmp = start+b+x+f
                    p = p[:i] + [(start, start+b)] + [(start+b+x, stop)] + p[i+1:]
                    dist[j] = start+b
                    break
        print dist[j]
    else:
        r = x-1
        t, x = rs[r]
        if len(p) == 0:
            p = [(0, l)]
        else:
            for i in xrange(len(p)):
                pocz, kon = p[i]
                if dist[r] == 0:
                    p = [(0, p[0][1])] + p[1:]
                elif dist[r] >= kon:
                    if i+1 < len(p): # jesli nie jest koniec parkingu
                        if dist[r]+x == p[i+1][0]:
                            p = p[:i] + [(pocz, p[i+1][1])] + p[i+2:]
                        else:
                            p = p[:i] + [(pocz, dist[r]+x+f)] + p[i+1:]
                    else: #jesli to jest koniec parkingu
                        p = p[:i] + [(pocz, l)]
                    break;

