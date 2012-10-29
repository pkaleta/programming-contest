import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline()[:-1]

hs = 0
for i in xrange(len(s)):
    if s[i] == 'H':
        hs += 1

ss = s+s

curVal = 0
minPos = -1
maxVal = 0

for i in xrange(hs):
    if s[i] == 'H':
        curVal += 1

maxVal = curVal


for i in xrange(hs, 2*n):
    if ss[i-hs] == 'H':
        curVal -= 1
    if ss[i] == 'H':
        curVal += 1
    if curVal > maxVal:
        maxVal = curVal

print hs-maxVal

