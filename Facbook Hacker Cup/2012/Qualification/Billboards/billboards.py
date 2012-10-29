import sys

T = int(sys.stdin.readline())

def check(w, h, size, words):
    lengths = map(lambda w: len(w), words)
    cur_width = 0
    rows = 1
    i = 0
    while i < len(lengths):
        if cur_width == 0:
            if lengths[i] * size > w:
                return False
            cur_width += lengths[i]
            i += 1
        else:
            if (cur_width + lengths[i] + 1) * size > w:
                rows += 1
                cur_width = 0
            else:
                cur_width += lengths[i] + 1
                i += 1
    return rows * size <= h

for t in xrange(1, T+1):
    line = sys.stdin.readline().split()
    w = int(line[0])
    h = int(line[1])
    words = line[2:]
    size = 0
    while size <= 1000 and check(w, h, size, words):
        size += 1
    print "Case #%d: %d" % (t, size-1)
