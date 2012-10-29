import sys

n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())
a = sorted(a)
eps = float(10)**float(-6)

def calc():
    for i in xrange(1, len(a)):
        if a[i-1] != a[i] and 2*a[i-1]>a[i]:
            return True
    return False

if calc():
    print "YES"
else:
    print "NO"

