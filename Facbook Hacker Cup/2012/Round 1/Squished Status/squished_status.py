import sys

MOD = 4207849484
MAX_LEN = 3000

lines = ' '.join(sys.stdin.readlines()).split()
n = int(lines[0])
lines = lines[1:]

def calc(m, s):
    dp = [0 for i in xrange(MAX_LEN)]
    for i in xrange(len(s)):
        for j in xrange(0, 3):
            if i-j >= 0:
                substring = s[i-j:i+1]
                if len(substring) > 0 and substring[0] != '0' and int(substring) <= m:
                    if i-j-1 < 0:
                        dp[i] = (dp[i] + 1) % MOD
                    else:
                        dp[i] = (dp[i] + dp[i-j-1]) % MOD
#    print dp[:len(s)]
    return dp[len(s)-1] % MOD

for i in xrange(0, len(lines), 2):
    m = int(lines[i])
    s = lines[i+1]
    print "Case #%d: %d" % ((i//2)+1, calc(m, s))
