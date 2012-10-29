import sys

maxn = 1000005

d = [0 for i in range(maxn)]

def calc(n):
    if n < 10:
        return n
    sum = 0
    s = str(n)
    for c in s:
        sum += int(c)
    return calc(sum)

for i in range(maxn):
    d[i] = calc(i)

mul = [[0 for i in range(100)] for j in range(100)]

##for i in range(1, 100):
##    for j in range(1, 100):
##        mul[i][j] = d[d[i]*d[j]]

result = [0 for i in range(maxn)]

for i in range(1, maxn):
    x = d[i]
#    print "%d: d = %d" % (i, x)
    result[i] = result[i-1]
    for j in range(1, x+1):
#        print "*** %d: d = %d,               %d %d" % (j, d[j], x*d[j], d[x*d[j]])
        if d[x*d[j]] <= i and i * j >= 10:
            result[i] += 2
print result
