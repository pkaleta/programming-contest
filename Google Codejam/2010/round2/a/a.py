import sys

ts = int(sys.stdin.readline())

def check(line):
    for i in xrange(len(line)):
        if line[i] != line[len(line)-1-i]:
            return False
    return True

def calc(line):
    result = 0
    i = 0
    while not check(line):
        line = line[:-1]
        result += 1
    return result

def rev(line):
    return line[::-1]

for t in xrange(ts):
    k = int(sys.stdin.readline())
    d = []
    od = []
    rowl = []
    rowr = []
    cold = []
    colu = []
    for i in xrange(2*k-1):
        oline = sys.stdin.readline()[:-1]
        od.append(oline)
        print od
        print rotate(od)
        line = map(int, oline.split())
        d.append(line)
        rowl.append(calc(line))
        rowr.append(calc(rev(line)))

