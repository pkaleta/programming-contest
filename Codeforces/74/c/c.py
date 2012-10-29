import sys

n, m, k = map(int, sys.stdin.readline().split())
d = map(int, sys.stdin.readline().split())

def calc():
    if n % 2 == 0:
        return 0

    ops = (n/2)+1
    if ops > m:
        return 0

    return min( (m/ops)*k, min(d[::2]))

print calc()
