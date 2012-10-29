import sys
n, k, p = map(int, sys.stdin.readline().split())

ret = []

for i in xrange(p):
    x = int(sys.stdin.readline())

    if k == n:
        ret.append('X')
    elif k == 1:
        if x == n:
            ret.append('X')
        else:
            ret.append('.')
    elif n % 2 == 0:
        if k > n/2:
            evenBegin = 1
            left = k-(n/2)
            oddBegin = n-2*left+1
        else:
            evenBegin = n-(2*k-1)+1
            oddBegin = n+1

        if x % 2 == 0:
            if x >= evenBegin:
                ret.append('X')
            else:
                ret.append('.')
        else:
            if x >= oddBegin:
                ret.append('X')
            else:
                ret.append('.')
    else:
        if k > n/2+1:
            oddBegin = 1
            left = k-(n/2+1)
            evenBegin = n-2*left+1
        else:
            oddBegin = n-(2*k-1)+1
            evenBegin = n+1

        if x == oddBegin:
            ret.append('.')
        elif x == oddBegin+1:
            ret.append('X')
        else:
            if x % 2 == 0:
                if x >= evenBegin:
                    ret.append('X')
                else:
                    if x >= oddBegin:
                        ret.append('X')
                    else:
                        ret.append('.')
            else:
                if x >= evenBegin-1:
                    if x >= oddBegin:
                        ret.append('X')
                    else:
                        ret.append('.')
                else:
                    ret.append('.')


print ''.join(ret)

