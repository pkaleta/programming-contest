import sys

x = list(sys.stdin.readline()[:-1])
n = len(x)


if len(x) == 1:
    print '0'
else:
    ret = n

    i = n-1
    while i+1 > 1:
        if x[i] == '1':
            ret += 1
            while i >= 0 and x[i] == '1':
                i -= 1
            if i >= 0:
                x[i] = '1'
                x = x[:i+1]
            else:
                break
        else:
            x = x[:-1]
            i -= 1

    print ret
