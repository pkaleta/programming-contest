import sys

t = int(sys.stdin.readline())

def cmp(a, b):
    if a[0] < b[0]:
        return 1
    elif a[0] == b[0]:
        return 0
    else:
        return -1

for c in range(t):
    p, k, l = [int(x) for x in sys.stdin.readline().split()]
    l = [(int(x), i) for i, x in enumerate(sys.stdin.readline().split())]
    l.sort(cmp)
    result = 0
    j = 0
    for i in range(len(l))[::k]:
        tmp = sum([ item[0] for item in l[i:i+k]])
        result += tmp * (j+1)
        j += 1
    print "Case #%d: %d" %(c + 1, result)
