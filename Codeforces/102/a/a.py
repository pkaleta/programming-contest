import sys

r1, r2 = map(int, sys.stdin.readline().split())
c1, c2 = map(int, sys.stdin.readline().split())
d1, d2 = map(int, sys.stdin.readline().split())


found = False
aa = -1
bb = -1
cc = -1
dd = -1

for a in xrange(1, 10):
    for b in xrange(1, 10):
        for c in xrange(1, 10):
            for d in xrange(1, 10):
                if a != b and a != c and a != d and b != c and b != d and c != d and a + b == r1 and c + d == r2 and a + c == c1 and b + d == c2 and a + d == d1 and b + c == d2:
                    aa = a
                    bb = b
                    cc = c
                    dd = d
                    found = True

if not found:
    print -1
else:
    print aa, bb
    print cc, dd
