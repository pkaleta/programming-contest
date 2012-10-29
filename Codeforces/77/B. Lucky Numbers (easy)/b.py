import sys

s = sys.stdin.readline()[:-1]
n = int(s)

ret = 9999999999999999999999

def cnt(s):
    c4 = 0
    c7 = 0
    for c in s:
        if c == '4':
            c4 += 1
        if c == '7':
            c7 += 1
    return c4 == c7

def find(s, maxLen):
    global ret
    if len(s) > maxLen:
        return
    x = int(s)

    if (x >= n and cnt(s) and x < ret):
        ret = x
    find(s+"4", maxLen)
    find(s+"7", maxLen)

find("4", 13)
find("7", 13)

print int(ret)

