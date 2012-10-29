import sys

n = int(sys.stdin.readline())
d = map(int, sys.stdin.readline().split())

a, b = map(int, sys.stdin.readline().split())

res = 0
for i in range(a-1, b-1):
    res += d[i]

print res
