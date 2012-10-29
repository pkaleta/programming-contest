import sys

s = sys.stdin.readline().strip()
p = sys.stdin.readline().strip()

def check(d, p):
    lack = 0
    for i in xrange(ord('a'), ord('z')+1):
        c = chr(i)
        if d[c] < dp[c]:
            lack += dp[c] - d[c]
    return lack

if len(s) < len(p):
    print 0
else:
    d = {'?':0}
    dp = {}
    for c in xrange(ord('a'), ord('z')+1):
        dp[chr(c)] = 0
        d[chr(c)] = 0

    ret = 0
    for i in xrange(len(s)):
        if i < len(p):
            d[s[i]] += 1
            dp[p[i]] += 1
        if i == len(p)-1:
            if check(d, p) == d['?']:
                ret += 1
        if i > len(p)-1:
            d[s[i-len(p)]] -= 1
            d[s[i]] += 1
            if check(d, p) == d['?']:
                ret += 1
    print ret
