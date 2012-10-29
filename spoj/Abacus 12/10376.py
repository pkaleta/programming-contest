import sys

T = int(sys.stdin.readline())

def solve(s, start):
    if start == len(s)-1:
        return 0

    p = [0, 0]
    t = 0
    for j in xrange(2, len(s)):
        while t > 0 and s[start+t+1] != s[start+j]:
            t = p[t]
        if s[start+t+1] == s[start+j]:
            t += 1
        p.append(t)
        if j % 2 == 0 and p[j] == j / 2:
            s[start+j] = '*'
            return 2 + solve(s, start+j)

for t in xrange(T):
    s = '*' + sys.stdin.readline().strip()
    print solve(list(s), 0)
