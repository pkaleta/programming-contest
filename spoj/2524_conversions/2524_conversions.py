import sys

tcs = int(sys.stdin.readline())

conv = {"kg" : (2.2046, "lb"),
        "lb" : (0.4536, "kg"),
        "l" : (0.2642, "g"),
        "g" : (3.7854, "l")}

for tc in xrange(tcs):
    n, unit = sys.stdin.readline().split()
    n = float(n)
    converted = conv[unit]
    ratio = converted[0]
    nunit = converted[1]
    print "%d %.4f %s" % (tc+1, n*ratio, nunit)
