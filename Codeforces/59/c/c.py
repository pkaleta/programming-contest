import sys

k = int(sys.stdin.readline())
line = sys.stdin.readline()[:-1]
s = [c for c in line]

chars = {'?' : 0}
for i in xrange(ord('a'), ord('z') + 1):
    chars[chr(i)] = False

def checkAndFill(s):
    count = 0
    r = len(s) / 2 + 1
    used = 0

    for i in xrange(r):
        a = s[i]
        b = s[len(s)-1-i]
        if a != '?' and b != '?' and a != b:
            return (False, '', -1)

        if a == '?':
            s[i] = b
        if b == '?':
            s[len(s)-1-i] = a

        if s[i] != '?':
            if not chars[s[i]]:
                used += 1
                chars[s[i]] = True

        tmp = s[i] == '?'

    return (True, s, used)

def next(cur, k):
    while chars[chr(cur)] == True and cur < ord('a') + k - 1:
        cur += 1
    return cur

def calc(s, k, aLeft):
    r = len(s) / 2 + 1

    result = [c for c in s]

    cur = ord('a')
    for i in xrange(r):
        if result[i] == '?':
            if aLeft > 0:
                result[i] = result[len(s)-1-i] = 'a'
                chars['a'] = True
                aLeft -= 1
            else:
                cur = next(cur, k)
                result[i] = result[len(s)-1-i] = chr(cur)
                chars[chr(cur)] = True
    return ''.join(result)

(possible, s, used) = checkAndFill(s)
count = 0
for c in s:
    count += c == '?'
count = (count + 1) / 2
#print "*********count", count, ", used: ", used, "*** ", s
tmp = count - (k - used)
if not chars['a']:
    tmp += 1
aLeft = max(0, tmp)
#print "*********", aLeft

if possible and k - used <= count:
    print calc(s, k, aLeft)
else:
    print "IMPOSSIBLE"

