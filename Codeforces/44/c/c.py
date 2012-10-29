import sys

n = int(sys.stdin.readline())

left = 10.0
right = 1000000000000000000L

stops = map(int, sys.stdin.readline().split())

curStop = 1
lastStop = stops[len(stops)-1]
for i in xrange(0, lastStop):
    while curStop != stops[i]:
        left = max(left, ((curStop+1)*10.0)/(i+1))
        curStop += 1

    right = min(right, ((stops[i]+1)*10.0)/(i+1))
    curStop = stops[i]+1
    if curStop >= lastStop:
        break

right = min(right, (lastStop+1)*10.0/len(stops))

def calcAmount(alfa, flag=False):
    amount = float(alfa)
    last = 0
    for i in xrange(0, len(stops)):
        amount = amount - (stops[i]-last)*10.0 + alfa
        if flag:
            amount -= 0.00000000000001
        last = stops[i]

    return amount


l = calcAmount(left, False)
r = calcAmount(right, True)

#print "**********", left, right
#print "**********", l, r

if int(l/10) == int(r/10):
    print "unique"
    print lastStop+int(l/10)
else:
    print "not unique"

