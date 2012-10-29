Max = 1000010
def fun(x):
    return x * 100.0 / (6 ** 31)

if __name__ == "__main__":
    n = 600
    k = Max

    t = [0 for i in range(k + 1)]
    tt = [0 for i in range(k + 1)]
    sizes = [(), (0, 5)]
    valid = [(), (1, 6)]
    res = [16] * 6

    totalLen = 6

    for c in range(1, 7):
        t[c] = 1;
    currLen = 10

    for r in range(2, n + 1):
        for c in range(1, currLen + 1):
            for d in range(1, 7):
                if c + d <= k:
                    tt[c + d] += t[c]

        currLen += 6
        begin = totalLen
        firstValid = lastValid = -1
        first = True

        for c in range(1, currLen + 1):
            t[c] = tt[c]
            m = t[c] * 100 / (6 ** r)
            if m >= 1:
                lastValid = c
                if first:
                    firstValid = c
                    first = False
                res.append(m)
                totalLen += 1

        tt = [0 for c in range(k + 1)]
        sizes.append((begin, totalLen - 1))
        valid.append((firstValid, lastValid))

#        print t[0 : 30]
#        print t[valid[r][0]-1 : valid[r][1]]
#        print map(fun, t[valid[r][0]-1 : valid[r][1]])
#        print res[sizes[r][0]:sizes[r][1] + 1]
#        print 
#        print res
#        print sizes
#        print valid
#        print '**********'



#    print res
#
#    for i in range(len(sizes)):
#        print 'sizes[%d][%d] = %d' % (i + 1, 0, sizes[i][0])
#        print 'sizes[%d][%d] = %d' % (i + 1, 1, sizes[i][1])
#
    for i in range(1, len(valid)):
        print 'valid[%d][%d] = %d' % (i, 0, valid[i][0])
        print 'valid[%d][%d] = %d' % (i, 1, valid[i][1])

#    z = 0
#    for i in range(n, currLen + 1):
#        m = t[i] * 100 / (6 ** n)
#        if (m >= 1):
#            z += 1
#    print z
