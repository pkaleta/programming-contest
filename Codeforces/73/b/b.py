import sys
from math import sqrt

n, m, maxDist = map(int, sys.stdin.readline().split())
keyboard = []
q = []
INF = float('inf')
d = {}

for i in xrange(n):
    line = list(sys.stdin.readline()[:-1])
    row = []
    for j in xrange(len(line)):
        if line[j] == 'S':
            q.append((j, i))
            row.append((line[j], 0))
        else:
            d[line[j]] = INF
            row.append((line[j], INF))
    keyboard.append(row)

def updateDict(ch, dist):
    if d.has_key(ch):
        curDist = d[ch]
        if curDist > dist:
            d[ch] = dist
    else:
        d[ch] = dist

for (x, y) in q:
    for i in xrange(n):
        for j in xrange(m):
            ch, dist = keyboard[i][j]
            if ch != 'S':
                updateDict(ch, sqrt( abs(j-x)**2 + abs(i-y)**2 ))


q = int(sys.stdin.readline())
s = list(sys.stdin.readline()[:-1])

res = 0
for ch in s:
    if ch >= 'A' and ch <= 'Z':
        downcase = chr(ord(ch)+32)
        if not d.has_key(downcase):
            res = -1
            break
        if d[downcase] == INF:
            res = -1
            break
        if d[downcase] > maxDist:
            res += 1
    elif ch >= 'a' and ch <= 'z':
        if not d.has_key(ch):
            res = -1
            break

print res
