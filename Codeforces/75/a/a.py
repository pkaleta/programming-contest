import sys

n, m = map(int, sys.stdin.readline().split())

i = 1;
while m >= i:
    m -= i

    i += 1
    if i > n:
        i = 1

print m
