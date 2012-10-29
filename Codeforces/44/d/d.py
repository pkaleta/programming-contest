import sys

LIMIT = 100005

count = [0]*LIMIT

n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())

for i in xrange(n):
    count[a[i]] += 1

for i in xrange(2, LIMIT):
    if count[i] > count[i-1]:
        print "-1"
        exit(0)

print count[1]
s = ""
for i in xrange(n):
    s += "%d " % count[a[i]]
    count[a[i]] -= 1

print s
