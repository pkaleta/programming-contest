import sys

def consume(line):
    n = int(line[0])
    items = line[1:n+1]
    line = line[n+1:]
    return (n, items, line)

def rev(s):
    return s[::-1]

def createCombines(n, items):
    d = {}
    for i in xrange(n):
        k = items[i][:2]
        v = items[i][2]
        d[k] = v
        d[rev(k)] = v
    return d

def createOpposite(n, items):
    d = {}
    for item in items:
        for i in xrange(len(item)):
            k = item[i]
            rest = item[:i]+item[i+1:]
            if d.has_key(k):
                d[k] = d[k].union(set(rest))
            else:
                d[k] = set(rest)
    return d

def createChars():
    chars = {}
    for c in xrange(ord('A'), ord('Z')+1):
        chars[c] = 0
    return chars

def addToChars(chars, c, val):
    if chars.has_key(c):
        chars[c] += val
    else:
        chars[c] = val

def incChars(chars, c):
    addToChars(chars, c, 1)

def decChars(chars, c):
    addToChars(chars, c, -1)

ts = int(sys.stdin.readline())
for t in xrange(ts):
    line = sys.stdin.readline().split()

    chars = createChars()

    c, cs, line = consume(line)
    d, ds, line = consume(line)
    n, ns, line = consume(line)
    ns = ns[0]

    combine = createCombines(c, cs)
    opposite = createOpposite(d, ds)

    s = []
    for i in xrange(n):
        s.append(ns[i])
        incChars(chars, ns[i])
        suffix = ''.join(s[-2:])

        if combine.has_key(suffix):
            comb = combine[suffix]
            decChars(chars, suffix[0])
            decChars(chars, suffix[1])
            incChars(chars, comb)
            s = s[:-2]
            s.append(comb)
        elif opposite.has_key(ns[i]):
            opps = list(opposite[ns[i]])
            for c in opps:
                if chars.has_key(c) and chars[c] > 0:
                    chars = createChars()
                    s = []
                    break

    print "Case #%d: [%s]" % (t+1, ', '.join(s))

