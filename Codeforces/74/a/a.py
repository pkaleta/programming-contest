import sys
from math import ceil

r, g, b = map(int, sys.stdin.readline().split())

tr = ceil(r/2.0)
tg = ceil(g/2.0)
tb = ceil(b/2.0)

xr = 3*(tr-1)
xg = 3*(tg-1)+1
xb = 3*(tb-1)+2

print int(30+max([xr, xg, xb]))
