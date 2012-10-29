import sys

T = int(sys.stdin.readline())

def bs(s, ll, l, r):
    if l == r:
        return l
    if l+1 == r:
        if hash(s[ll:r]) == hash(s[:r-ll]):
            return r
        else:
            return l
    m = (l + r) / 2
    if hash(s[ll:m]) == hash(s[:m-ll]):
        return bs(s, ll, m, r)
    else:
        return bs(s, ll, l, m)

for t in xrange(T):
    s = sys.stdin.readline().strip()

    ret = len(s)
    for i in xrange(1, len(s)):
        m = bs(s, i, i, len(s))
        ret += m-i
    print ret
