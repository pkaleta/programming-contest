import sys

ts = int(sys.stdin.readline())

def last(row):
    result = 0
    for i in xrange(len(row)):
        if row[i] == '1':
            result = i+1
    return result

def calc(d):
    result = 0
    for i in xrange(1, len(d)):
        if d[i] > i:
            for j in xrange(i+1, len(d)):
                if d[j] <= i:
                    tmp = d[j]
                    for k in xrange(j, i, -1):
                        d[k] = d[k-1]
                    d[i] = tmp
                    result += j-i
                    break
    return result

for t in xrange(ts):
    d = [-1]

    n = int(sys.stdin.readline())
    for i in xrange(n):
        row = sys.stdin.readline()[:-1]
        d.append(last(row))

    print "Case #%d: %d" % (t+1, calc(d))
