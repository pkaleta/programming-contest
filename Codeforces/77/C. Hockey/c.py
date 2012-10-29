import sys
import re
import string


n = int(sys.stdin.readline())
s = []

for i in xrange(n):
    tmp = sys.stdin.readline()[:-1]
    s.append(tmp.lower())

w = sys.stdin.readline()[:-1]
letter = sys.stdin.readline()[:-1]

l = len(w)
ww = w.lower()
t = [0 for i in xrange(l)]

for pat in s:
    ss = s
    for i in xrange(len(ww)):
        if ww[i:].find(pat) == 0:
            for j in xrange(i, i+len(pat)):
                t[j] = 1

ret = ""
for i in xrange(len(w)):
    if t[i] == 1:
        if w[i].lower() == letter.lower():
            if w[i] in string.lowercase:
                if w[i] == 'a':
                    ret += 'b'
                else:
                    ret += 'a'
            else:
                if w[i] == 'A':
                    ret += 'B'
                else:
                    ret += 'A'
        else:
            if w[i] in string.lowercase:
                ret += letter.lower()
            else:
                ret += letter.upper()
    else:
        ret += w[i]

print ret
