import sys

n = int(sys.stdin.readline())
d = {}

def cntAmp(s):
    amp = 0
    i = 0
    while i < len(s) and s[i] == "&":
        amp += 1
        i += 1

    return amp

def cntStar(s):
    star = 0
    i = len(s)-1
    while i >= 0 and s[i] == "*":
        i -= 1
        star += 1

    return star


def typedef(a, b):
    amp = cntAmp(a)
    star = cntStar(a)

    name = a.strip("&*")

    if name == "errtype":
        d[b] = -1
    elif name == "void":
        if star-amp < 0:
            d[b] = -1
        else:
            d[b] = star-amp
    else:
        if not d.has_key(name):
            d[b] = -1
        else:
            if d[name] < 0:
                d[b] = -1
            else:
                d[b] = d[name]+star-amp


def typeof(a):
    amp = cntAmp(a)
    star = cntStar(a)

    a = a.strip("&*")


    if a == "void":
        if star-amp < 0:
            return "errtype"
        else:
            ret = "void"
            for i in xrange(star-amp):
                ret += "*"
            return ret
    elif a == "errtype":
        print "errtype"
    elif d.has_key(a):
        if d[a] < 0:
            return "errtype"
        else:
            cnt = d[a]+star-amp

            if cnt < 0:
                return "errtype"
            else:
                ret = "void"
                for i in xrange(cnt):
                    ret += "*"
                return ret
    else:
        return "errtype"

for i in xrange(n):
    line = sys.stdin.readline()[:-1]
    ops = line.split()

    if ops[0] == "typedef":
        typedef(ops[1], ops[2])
    elif ops[0] == "typeof":
        print typeof(ops[1])
#    print line
#    print d
#    print 
