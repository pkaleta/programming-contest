import sys

n, l = map(int, sys.stdin.readline().split())
a = map(int, sys.stdin.readline().split())

res = 0
for i in range(l, 101):
    tmp = 0
    for p in a:
        tmp += (p/i)*i
    if tmp > res:
        res = tmp

print res

