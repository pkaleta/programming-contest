import sys

s1 = sys.stdin.readline().strip()
s2 = sys.stdin.readline().strip()

n = len(s1)
m = len(s2)
ret = 0

for i in xrange(1, n+1):
    if n % i == 0 and m % i == 0:
        if s1[:i] * (m / i) == s2 and s1[:i] * (n / i) == s1:
            ret += 1

print ret
