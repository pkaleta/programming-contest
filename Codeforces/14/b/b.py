import sys

n, x0 = map(int, sys.stdin.readline().split())
t = [0 for i in range(1005)]

for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    s = min(a, b)
    e = max(a, b)
    for j in range(s, e+1):
        t[j] += 1;

result = 99999
for i in range(x0, 1000):
    if t[i] == n:
        result = i-x0
        break

for i in range(0, x0):
    if t[i] == n:
        result = min(result, x0-i)

if result == 99999:
    print "-1"
else:
    print result

