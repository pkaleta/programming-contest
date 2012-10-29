import sys

t = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

d = {"S":0, "M":1, "L":2, "XL":3, "XXL":4}
x = [0, 1, -1, 2, -2, 3, -3, 4, -4]
dd = ["S", "M", "L", "XL", "XXL"]

for i in xrange(k):
    size = sys.stdin.readline()[:-1]
    j = 0
    while j < len(x):
        tmp = d[size] + x[j]
        if tmp >= 0 and tmp < 5 and t[tmp] > 0:
            t[tmp] -= 1
            print dd[tmp]
            break;
        j += 1

