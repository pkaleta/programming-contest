import sys

k = int(sys.stdin.readline())
l = int(sys.stdin.readline())
m = int(sys.stdin.readline())
n = int(sys.stdin.readline())
d = int(sys.stdin.readline())

ret = 0
for i in xrange(1, d+1):
    if i % k == 0 or i % l == 0 or i % m == 0 or i % n == 0:
        ret += 1
print ret
