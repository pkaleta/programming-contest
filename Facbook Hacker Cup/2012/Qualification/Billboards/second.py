import sys

T = int(sys.stdin.readline())

def check(w, h, text, size):
    prev = 0
    rows = 1
    while True:
        flag = False
        for i in xrange(len(text)):
            if text[i] == ' ':
                if i * size > w:
                    if prev == 0:
                        return False
                    text = text[prev+1:]
                    rows += 1
                    prev = 0
                    flag = True
                    break
                else:
                    prev = i
        if not flag:
            break
    return (rows * size) <= h

for t in xrange(1, T+1):
    line = sys.stdin.readline().split()
    w = int(line[0])
    h = int(line[1])
    text = ' '.join(line[2:]) + ' '
    size = 0
    while size <= 1000 and check(w, h, text, size):
        size += 1
    print "Case #%d: %d" % (t, size-1)
