import sys

if __name__ == "__main__":
    tcs = int(sys.stdin.readline())
    for tc in xrange(tcs):
        n = int(sys.stdin.readline())
        men = sorted(map(int, sys.stdin.readline().split()))
        women = sorted(map(int, sys.stdin.readline().split()))
        result = sum([men[i]*women[i] for i in xrange(n)])
        print result
