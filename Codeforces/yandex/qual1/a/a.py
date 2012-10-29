import sys

s = sys.stdin.readline()[:-1]
t = []
counter = 0
flag = True

while flag:
    t = []
    counter = 0
    for i in xrange(len(s)):
        if s[i] != s[i-1]:
            if counter % 2 != 0:
                t.append(s[i-1])
            else:
                counter = 1
        else:
            counter += 1
    if counter % 2 != 0:
        t.append(s[len(s)-1])

    flag = len(s) != len(t)
    s = t

print ''.join(t)
