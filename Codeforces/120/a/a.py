import sys

n, m = map(int, sys.stdin.readline().split())

if n == 0 and m > 0:
    print "Impossible"
else:
    max_price = n + m - min(m, 1)
    min_price = n + m - min(n, m)
    print min_price, max_price
