import sys

a, b, n = map(int, sys.stdin.readline().split())

if b == 0 and a != 0:
    print "0"
elif a == 0 and b != 0:
    print "No solution"
elif a == 0 and b == 0:
    print "1"
else:
    if b % a != 0:
        print "No solution"
    else:
        flag = False
        m = float(b)/float(a)

        if m < 0:
            flag = True
            m = -m

        x = int(pow(m, float(1)/float(n)));

        tmp = a*pow(x, n)

        if tmp == b:
            print x
        elif -tmp == b:
            print -x
        else:
            print "No solution"
