import sys

A = 5402147
B = 54321
M = 10000001

def test(n, obs):
    if n < M:
        for o in obs:
            n = (A * n + B) % M
            if n % 1000 != o:
                return (None, False)
        return (n, True)
    else:
        return (None, False)

def calc(n):
    res = []
    for i in xrange(10):
        n = (A * n + B) % M
        res.append(n % 1000)
    return res

T = int(sys.stdin.readline())
for t in xrange(T):
    tmp = map(int, sys.stdin.readline().split())
    N = tmp[0]
    obs = tmp[1:]

    next = None
    count = 0
    for i in xrange(10001):
        n = i * 1000 + obs[0]
        num, correct = test(n, obs[1:])
        if correct == True:
            count += 1
            next = num

    if count == 0:
        print "Wrong machine"
    elif count > 1:
        print "Not enough observations"
    else:
        print ' '.join(map(str, calc(next)))


