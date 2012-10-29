import sys

n = map(int, list(sys.stdin.readline()[:-1]))

i = 0
while len(n) > 1:
    i += 1
    n = map(int, list(str(sum(n))))

print i

