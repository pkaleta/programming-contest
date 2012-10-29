import sys

s = list(sys.stdin.readline()[:-1])
left = int(sys.stdin.readline())
d = {}

for c in xrange(ord('a'), ord('z')+1):
    d[chr(c)] = 0

for i in xrange(len(s)):
    d[s[i]] += 1

l = d.items()

srt = filter(lambda (a, b): b > 0, sorted(l, key = lambda (a, b): b))
diff = len(srt)
chars = {}

for (c, v) in srt:
    if left >= v:
        left -= v
        diff -= 1
        chars[c] = True
    else:
        break

print diff

ss = []
for i in xrange(len(s)):
    if not chars.has_key(s[i]):
        ss.append(s[i])

print ''.join(ss)

