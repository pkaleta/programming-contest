import sys

T = int(sys.stdin.readline())
MOD = 1000000007

for t in xrange(T):
    n = int(sys.stdin.readline())
    c = sorted(map(int, sys.stdin.readline().split()))
    ret = 1
    if c[0] != 0:
        print 0
    else:
        for i in xrange(1, n):
            cnt = i-(c[i]-1)
            if cnt <= 0:
                ret = 0
                break
            ret = (ret * cnt) % MOD
        print ret
