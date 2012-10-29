import sys

n, m = map(int, sys.stdin.readline().split())
grades = []
for i in xrange(n):
    grades.append(sys.stdin.readline().strip())

ret = 0
for i in xrange(n):
    for j in xrange(m):
        best = True
        for k in xrange(n):
            if i != k and grades[i][j] < grades[k][j]:
                best = False
                break
        if best:
            ret += 1
            break
print ret
