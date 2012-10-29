import sys

n = int(sys.stdin.readline())
INF = float('inf')

mina = INF
minb = INF
a = 0
while a <= n/4:
    if (n-4*a) % 7 == 0:
        b = (n-4*a) / 7
        if mina+minb > a+b:
            mina = a
            minb = b
        elif mina+minb == a+b:
            if a > mina:
                mina = a
                minb = b
    a += 1

if mina == INF or minb == INF:
    print -1
else:
    ret = []
    for i in xrange(mina):
        ret.append('4')
    for i in xrange(minb):
        ret.append('7')
    print ''.join(ret)

