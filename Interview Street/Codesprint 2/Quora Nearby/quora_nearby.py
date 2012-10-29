import sys

t, q, n = map(int, sys.stdin.readline().split())
topics = {}
questions = {}
distX = 0
distY = 0

def dist((x1, y1), (x2, y2)):
    return (y1-y2)**2+(x1-y2)**2

def dstCmp((id, pos)):
    return (dist(pos, (distX, distY)), -int(id))

def findClosest(ids):
    minDist = float('inf')
    minTopic = None
    for id in ids:
        d = dist(topics[id], (distX, distY))
        if d < minDist:
            minDist = d
            minTopic = topics[id]
    return minTopic

for i in xrange(t):
    id, x, y = sys.stdin.readline().split()
    topics[id] = (float(x), float(y))

for i in xrange(q):
    line = sys.stdin.readline().split()
    id = line[0]
    qn = int(line[1])
    if qn > 0:
        ts = line[2:]
        questions[id] = ts

for i in xrange(n):
    c, r, x, y = sys.stdin.readline().split()
    r = int(r)
    distX = float(x)
    distY = float(y)
    if c == 'q':
        qs = []
        for (id, ts) in questions.items():
#            print "question:", id, findClosest(ts)
            qs.append((id, findClosest(ts)))
        qs = sorted(qs, key = dstCmp)
        print ' '.join(map(lambda (id, _): id, qs[:r]))
    else:
        ts = sorted(topics.items(), key = dstCmp)
        print ' '.join(map(lambda (id, _): id, ts[:r]))
