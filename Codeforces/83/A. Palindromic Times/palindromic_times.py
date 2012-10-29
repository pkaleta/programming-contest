import sys

h, m = sys.stdin.readline()[:-1].split(":")

while True:
    mm = int(m)
    hh = int(h)
    mm += 1

    if mm >= 60:
        hh += 1
        mm = 0
    if hh >= 24:
        hh = 0

    h = str(hh)
    if len(h) == 1:
        h = '0'+h
    m = str(mm)
    if len(m) == 1:
        m = '0'+m
    if h == m[::-1]:
        break

print h + ":" + m

