import sys

ts = int(sys.stdin.readline())

def check(b1, b2):
    if b1[3]+1 >= b2[1] and b1[3]+1 <= b2[3] and \
            b2[2]+1 >= b1[0] and b1[2] > b2[0]:
                return True
    return False


for t in xrange(ts):
    r = int(sys.stdin.readline())
    for i in xrange(r):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        for (
