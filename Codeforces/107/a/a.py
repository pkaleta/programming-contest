import sys

n, k, l, c, d, p, nl, np = map(int, sys.stdin.readline().split())

print min(k*l/nl, c*d, p/np)/n
