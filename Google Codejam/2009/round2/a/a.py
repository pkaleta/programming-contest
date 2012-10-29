import sys

t = int(sys.stdin.readline())

def lst(row):
    res = -1
    for i in range(len(row)):
        if row[i] == '1':
            res = i
    return res

def correct(last):
    for i in range(len(last)):
        if last[i] > i:
            return False
    return True

def find(i, last):
    for j in range(i + 1, len(last)):
        if last[j] <= i:
            return j


for case in range(t):
    last = []

    n = int(sys.stdin.readline())
    for i in range(n):
        row = sys.stdin.readline()
        last.append(lst(row))

    res = 0
    while not correct(last):
        for i in range(len(last)):
            if (last[i] > i):
                j = find(i, last)
                res += j - i
                last = last[0:i] + [last[j]] + last[i:j] + last[j+1:]
                break



    print "Case #%d: %d" % (case + 1, res)
