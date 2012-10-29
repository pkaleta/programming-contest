import sys

t = int(sys.stdin.readline())

def cross(l1, l2, k):
    for i in range(k):
        if l1[i] == l2[i]:
            return True
    for i in range(1, k):
        if (l1[i - 1] > l2[i - 1] and l1[i] < l2[i]) or (l1[i - 1] < l2[i - 1] and l1[i] > l2[i]):
            return True
    return False

for case in range(t):
    lines = []
    n, k = map(int, sys.stdin.readline().split())
    for i in range(n):
        line = map(int, sys.stdin.readline().split())
        lines.append(line)
    res = 0
    while len(lines) > 0:
        res += 1
        s = [lines[0]]
        for i in range(1, len(lines)):
            crs = False
            for j in range(len(s)):
                if cross(lines[i], lines[j], k):
                    crs = True
                    break
            if not crs:
                s.append(lines[i])
        print s
        for l in s:
            lines.remove(l)
    print "Case #%d: %d" % (case + 1, res)
