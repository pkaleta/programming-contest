import sys

s = sys.stdin.readline()[:-1]
d = {}

result = 0

for i in xrange(len(s)):
    for j in xrange(i+1, len(s)):
        k = 0
        while i+k < len(s) and j+k < len(s) and s[i+k] == s[j+k]:
            k += 1
        if k > result:
            result = k

print result
