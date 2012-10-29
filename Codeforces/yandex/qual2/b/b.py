import sys

n = int(sys.stdin.readline())
if (n == 2):
    line = map(int, sys.stdin.readline().split())[1:]
    print "1 %d\n%d %s" % (line[0], len(line)-1, ' '.join(map(str, line[1:])))
else:
    d = {}
    for i in xrange(300):
        d[i] = []

    sets = {}

    x = n * (n-1) / 2
    for i in xrange(x):
        line = map(int, sys.stdin.readline().split())
        m = line[0]
        line = line[1:]

        for elem in line:
            d[elem].append(i)

    for (k, v) in d.items():
        t = tuple(v)
        if v != []:
            if sets.has_key(t):
                sets[t].append(k)
            else:
                sets[t] = [k]

    for x in sets.values():
        print len(x), ' '.join(map(str, x))
