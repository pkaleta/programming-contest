import sys

s = sys.stdin.readline()[:-1]
toks = []

while len(s) > 0:
    i = 0
    tok = []

    if (s[0] == ' '):
        s = s[1:]
    elif s[0] >= '0' and s[0] <= '9':
        while i < len(s) and s[i] >= '0' and s[i] <= '9':
            tok.append(s[i])
            i += 1
        toks.append((1, ''.join(tok)))
        s = s[i:]
    elif s[0] == '.':
        toks.append((2, '...'))
        s = s[i+3:]
    elif s[0] == ',':
        toks.append((3, s[0]))
        s = s[1:]

out = []
last = -1
for i in xrange(len(toks)):
    if toks[i][0] == 1:
        if last == 1:
            out.append(" ")
        out.append(toks[i][1])

    if toks[i][0] == 2:
        if i > 0 and last != 3:
            out.append(" ")
        out.append(toks[i][1])

    if toks[i][0] == 3:
        out.append(toks[i][1])
        if i < len(toks)-1:
            out.append(" ")
    last = toks[i][0]

print ''.join(out)
