import sys

n, m = map(int, sys.stdin.readline().split())
bs = []
begin = {}
dp = {}
MOD = 1000000007

def binsearch(x, l, r):
    while l < r:
        m = (l+r)//2
        mval = bs[m][1]
        if mval < x:
            l = m+1
        elif mval > x:
            r = m
        else:
            return m
    return l


def calc(k):
#    print k, "***********"
    if k == 1:
        return len(begin[1]) % MOD
    if dp.has_key(k):
        return dp[k] % MOD

    ret = 0
    if begin.has_key(k):
        for beg in begin[k]:
            if beg == 0:
                ret = (ret + 1) % MOD
            i = binsearch(beg, 0, len(bs))
#            print "i: ", beg, i, bs[i][1]
            while bs[i][1] < k:
                ret = (ret + calc(bs[i][1])) % MOD
                i += 1
    dp[k] = ret % MOD
    return ret % MOD


for i in xrange(m):
    a, b = map(int, sys.stdin.readline().split())
    bs.append((a, b))
    if begin.has_key(b):
        begin[b].append(a)
    else:
        begin[b] = [a]

bs = sorted(bs, key = lambda (a, b): b)

print calc(n);
