import sys

p = []

for i in xrange(8):
    x, y = map(int, sys.stdin.readline().split())
    p.append((x, y))

def sqr(x):
    return x**2

def isRect((x1, y1), (x2, y2), (x3, y3), (x4, y4)):
    cx = (x1+x2+x3+x4)/4.0
    cy = (y1+y2+y3+y4)/4.0
    dd1 = sqr(cx-x1)+sqr(cy-y1)
    dd2 = sqr(cx-x2)+sqr(cy-y2)
    dd3 = sqr(cx-x3)+sqr(cy-y3)
    dd4 = sqr(cx-x4)+sqr(cy-y4)
    return abs(dd1-dd2) < 1e-6 and abs(dd1-dd3) < 1e-6 and abs(dd1-dd4) < 1e-6

def dist((x1, y1), (x2, y2)):
    return sqr(abs(x1-x2))+sqr(abs(y1-y2))

def sameDist(a, b, c, d):
    return abs(dist(a, b)-dist(c, d)) < 1e-6

def isSquare(a, b, c, d):
    x1, y1 = a
    x2, y2 = b
    x3, y3 = c
    x4, y4 = d
    if not isRect(a, b, c, d):
        return False

    if sameDist(a, b, b, c) and sameDist(c, d, d, a) and sameDist(a, c, b, d):
        return True
    if sameDist(a, b, b, d) and sameDist(d, c, c, a) and sameDist(a, d, b, c):
        return True

    if sameDist(a, c, c, d) and sameDist(d, b, b, a) and sameDist(a, d, c, b):
        return True
    if sameDist(a, c, c, b) and sameDist(b, d, d, a) and sameDist(a, b, c, d):
        return True

    if sameDist(a, d, d, b) and sameDist(b, c, c, a) and sameDist(a, b, d, c):
        return True
    if sameDist(a, d, d, c) and sameDist(c, b, b, a) and sameDist(a, c, d, b):
        return True


found = False
for a in xrange(8):
    if found:
        break
    for b in xrange(8):
        if found:
            break
        for c in xrange(8):
            if found:
                break
            for d in xrange(8):
                if found:
                    break
                if len(set([a, b, c, d])) == 4:
                    if isSquare(p[a], p[b], p[c], p[d]):
                        e, f, g, h = list(set(range(8))-set([a, b, c, d]))
                        if isRect(p[e], p[f], p[g], p[h]):
                            found = True
                            print "YES"
                            print a+1, b+1, c+1, d+1
                            print e+1, f+1, g+1, h+1
                            break

if not found:
    print "NO"
