import sys

T = int(sys.stdin.readline())

for t in xrange(1, T+1):
    count = {' ' : 0}
    for c in xrange(ord('A'), ord('Z')+1):
        count[chr(c)] = 0
    line = sys.stdin.readline().strip()
    for c in line:
        count[c] += 1
    count['C'] /= 2
    print "Case #%d: %d" % (t, min(map(lambda c: count[c], "HACKERCUP")))

