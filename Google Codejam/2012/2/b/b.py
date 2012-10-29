import sys

T = int(sys.stdin.readline())

for t in xrange(T):
    N, W, L = map(int, sys.stdin.readline().split())
    rads = sorted(enumerate(map(int, sys.stdin.readline().split())), key=lambda x: x[1])[::-1]

    if W > L:
        x = -rads[0][1]
        y = 0.0
        w_longer = True
    else:
        x = 0.0
        y = -rads[0][1]
        w_longer = False

    ret = []
    first = rads[0][1]
    for i, r in rads:
        if w_longer:
            if x + 2*r > W:
                x = 0.0
                y += first + r
                first = r
            ret.append((i, x+r, y))
            x += 2*r
        else:
            if y + 2*r > L:
                x += first + r
                first = r
                y = 0.0
            ret.append((i, x, y+r))
            y += 2*r

    ret = sorted(ret)
    r = []
    for i, x, y in ret:
        r.append(str(x))
        r.append(str(y))
    print "Case #%d: %s" % (t+1, ' '.join(r))
