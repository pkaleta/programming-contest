import sys

t = int(sys.stdin.readline())

for case in range(t):
    d = {}
    s = sys.stdin.readline().strip()
    d[s[0]] = 1;
    tmp = ['1']
    cur = 0
    for c in s[1:]:
        if d.has_key(c):
            tmp.append(str(d[c]))
        else:
            if (cur >= 10):
                d[c] = chr(cur + 87)
            else:
                d[c] = str(cur)
            tmp.append(d[c])
            cur += 1
            if cur == 1:
                cur += 1
    print "Case #%d: %s" % (case + 1, int(''.join(tmp), max(cur, 2)))
