import sys

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        n, m = map(int, sys.stdin.readline().split())
        if n <= m:
            print "0.00"
        else:
            print "%d.00" % (2 ** (n+1) - 2 ** (m+1))
