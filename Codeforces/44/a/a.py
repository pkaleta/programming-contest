import sys

t = [0, 0, 0]
v = [0, 0, 0]

t[0] = sys.stdin.readline()[0]
t[1] = sys.stdin.readline()[0]
t[2] = sys.stdin.readline()[0]

res = -1;

for i in xrange(3):
    for j in xrange(3):
        if i != j:
            if t[i] == "p" and t[j] == "r":
                v[i] += 1
            elif t[i] == "r" and t[j] == "s":
                v[i] += 1
            elif t[i] == "s" and t[j] == "p":
                v[i] += 1

            if v[i] > res:
                res = i

c = 0
flag = False

for i in xrange(3):
    if v[i] == v[res] and i != res:
        flag = True

if flag:
    print "?"
else:
    if res == 0:
        print "F"
    elif res == 1:
        print "M"
    else:
        print "S"

