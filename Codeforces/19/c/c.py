import sys

n = int(sys.stdin.readline())

s = map(int, sys.stdin.readline().split())

def check(i, l):
    for j in xrange(l):
        if i+l+j >= len(s) or s[i+j] != s[i+l+j]:
            return False
    return True

l = 1
while(2*l <= len(s)):
    found = False
    for i in xrange(len(s)):
        if check(i, l):
            found = True
            s = s[i+l:]
            break
    if not found:
        l += 1

print len(s)
for c in s:
    print "%d" % c,
