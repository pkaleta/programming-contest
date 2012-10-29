import sys

n = int(sys.stdin.readline())
hs = map(int, sys.stdin.readline().split())

def calc(i):
    result = 1
    j = i-1
    while j >= 0 and hs[j] <= hs[j+1]:
        result += 1
        j -= 1
    j = i+1
    while j < n and hs[j] <= hs[j-1]:
        result += 1
        j += 1
    return result

result = 1
for i in xrange(n):
    result = max(result, calc(i))

print result
