import sys

n = int(sys.stdin.readline())
for i in xrange(n):
    s = sys.stdin.readline().strip()
    l = len(s)
    check = True
    for i in xrange(1, l):
        if s[i] != s[0]:
            check = False
            break
    count = {'a':0, 'b':0, 'c':0}
    for i in xrange(0, l):
        count[s[i]] += 1
    if check:
        print l
    elif count['a'] % 2 == count['b'] % 2 == count['c'] % 2:
        print 2
    else:
        print 1
