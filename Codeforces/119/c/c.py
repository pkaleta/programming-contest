import sys
from itertools import takewhile

n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())
b = map(int, sys.stdin.readline().split())

i = n-1
j = n-1
ret = 0
last_changed = n
cur = 0
moved = set()
while i >= 0 and j >= 0:
    if b[j] in moved:
        j -= 1
    elif a[i] == b[j]:
        cur += 1
        i -= 1
        j -= 1
    else:
        moved.add(a[i])
        ret += cur + 1
        cur = 0
        i -= 1


print ret
