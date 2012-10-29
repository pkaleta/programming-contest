import sys
import copy

s = sys.stdin.readline()[:-1]


def check(s):
    for i in xrange(0, len(s)):
        cnt = 0
        j = i
        while j < len(s) and s[i] == s[j]:
            cnt += 1
            j += 1

        if cnt >= 7:
            return True
        else:
            continue
    return False


if check(s):
    print "YES"
else:
    print "NO"

