import sys

MOD = 4207849484
MAX_LEN = 3000

lines = ' '.join(sys.stdin.readlines()).split()
n = int(lines[0])
lines = lines[1:]

def calc(prev, m, s):
    if len(s) == 0:
        return 1
    cur = s[0]
    ret = 0;

    if (len(prev) > 0 or cur != '0') and int(prev + cur) <= m:
        ret += calc(prev + cur, m, s[1:])

    if cur != '0' and len(prev) > 0 and int(cur) <= m:
        ret += calc(cur, m, s[1:])

    return ret

for i in xrange(0, len(lines), 2):
    m = int(lines[i])
    s = lines[i+1]
    print "Case #%d: %d" % ((i//2)+1, calc('', m, s) % MOD)
