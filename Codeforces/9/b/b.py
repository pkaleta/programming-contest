import sys
from math import sqrt


n, vb, vs = map(int, sys.stdin.readline().split())

x = map(int, sys.stdin.readline().split())

xu, yu = map(int, sys.stdin.readline().split())

def dist(x, y):
    return sqrt((x-xu)**2+(y-yu)**2)

def time(i):
    return float(x[i]-x[0])/float(vb)+dist(x[i], 0)/float(vs)

min_stop = 1
min_time = time(min_stop)

for i in xrange(2, n):
    cur_time = time(i)
    if (cur_time < min_time) or \
            (cur_time == min_time and dist(x[i], 0) < dist(x[min_stop], 0)):
        min_time = cur_time
        min_stop = i

print min_stop+1
