import sys
from math import log

n = int(sys.stdin.readline())

if n <= 5:
    print ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"][n-1]
else:
    x = int(log(n/5+1, 2))
    s = 5*((2**x)-1)
    diff = n - s - 1

    print s
    a = int(diff / 2**x)
    print ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"][a]

