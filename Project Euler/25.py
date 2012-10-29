import sys

a = 1
b = 1
n = 2

while len(str(b)) < 1000:
    tmp = a
    a = b
    b += tmp
    n += 1

print n


