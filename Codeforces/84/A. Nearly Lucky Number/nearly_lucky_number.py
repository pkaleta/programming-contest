import sys

n = map(int, list(sys.stdin.readline()[:-1]))

num = {}

for i in xrange(10):
    num[i] = 0

for d in n:
    num[d] += 1

x = num[4] + num[7]
s = map(int, list(str(x)))

for i in xrange(9):
    num[i] = 0

def check(s):
    for d in s:
        if d != 4 and d != 7:
            return False
    return True

if check(s):
    print "YES"
else:
    print "NO"
