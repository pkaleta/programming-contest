import sys
import math

maxk = 100

inf = float("infinity")

n, k = map(int, sys.stdin.readline().split())
M = map(int, sys.stdin.readline().split())

xc = yc = math.ceil(k/2.0)

hall = [[k, 1] for i in range(maxk)]

def dist(x, y, m):
    result = abs(x-xc)*m
    for i in range(m):
        result += abs(y+i-yc)
    return result


def calc(row, m):
    a, b = hall[row]
    if a == k:
        l = (k-m)/2+1
        d = dist(row, l, m)
        return (d, l)
    else:
        left = inf
        right = inf
        ll = -1;
        lr = -1
        if a >= m:
            ll = a-m+1
            left = dist(row, ll, m)
        if k-b+1 >= m:
            lr = b
            right = dist(row, lr, m)
        if left <= right:
            return (left, ll)
        else:
            return (right, lr)

def place(m):
    min_cost = inf
    min_row = -1
    left = -1
    for row in range(1, k+1):
        c, l = calc(row, m)
#        print "row: %d, left: %d, right: %d, cost: %f" % (row, l, l+m-1, c)
        if c < min_cost:
            min_cost = c
            min_row = row
            left = l
    if min_row >= 1:
        hall[min_row][0] = min(hall[min_row][0], left-1)
        hall[min_row][1] = max(hall[min_row][1], left+m)
#    print "****************"
#    for i in range(1, k+1):
#        print hall[i]
    return (min_row, left)

for m in M:
    row, l = place(m)
    if row == -1:
        print -1
    else:
        print "%d %d %d" % (row, l, l+m-1)
