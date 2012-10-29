import sys

n = int(sys.stdin.readline())

def isam(line):
    return line[7] == 'a'

def ispm(line):
    return line[7] == 'p'

def gettime(line):
    h = int(line[1:3])
    m = int(line[4:6])
    if isam(line) and h == 12:
        h = 0
    if ispm(line) and h != 12:
        h += 12
    return (h, m)

def isearlier(l1, l2):
    h1, m1 = gettime(l1)
    h2, m2 = gettime(l2)

    if h1 < h2:
        return True
    elif h1 == h2:
        if m1 < m2:
            return True
        else:
            return False
    else:
        return False

def issame(l1, l2):
    h1, m1 = gettime(l1)
    h2, m2 = gettime(l2)
    return h1 == h2 and m1 == m2

lines = []
result = 1
counter = 0
for i in xrange(n):
    line = sys.stdin.readline()

    if len(lines) >= 1:
        if issame(line, lines[-1]):
            counter += 1
        else:
            counter = 0

        if counter >= 10 or isearlier(line, lines[-1]):
            counter = 0
            result += 1
            lines = [line]
        else:
            lines.append(line)
    else:
        lines.append(line)

print result
