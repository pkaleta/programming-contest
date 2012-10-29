import sys

n, m, a, b = map(int, sys.stdin.readline().split())

if m == 1:
    print 1
else:
    a -= 1
    b -= 1

    top = m-(a%m)
    bottom = (b%m)+1

#    print top, bottom

    if (a == b):
        print 1
    elif (b+1 == n):
        if top == m:
            print 1
        elif (a/m) == (b/m):
            print 1
        else:
            print 2
    elif (a / m) == (b / m):
        print 1
    elif top == m and bottom == m:
        print 1
    elif top + bottom == m:
        print 2
    elif top == m:
        print 2
    elif bottom == m:
        print 2
    else:
        if (a / m)+1 == (b / m):
            print 2
        else:
            print 3

