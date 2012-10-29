import sys

ad = sys.stdin.readline()[:-1]
bd = sys.stdin.readline()[:-1]


a = map(int, ad.split("."))
b = map(int, bd.split("."))

def is_valid(date):
    d = date[0]
    m = date[1]
    y = date[2]
    isleap = y % 4 == 0

    if m > 12:
        return False
    if m == 2:
        if isleap:
            if d > 29:
                return False
        else:
            if d > 28:
                return False
    if m in [1, 3, 5, 8, 10, 12]:
        if d > 31:
            return False
    if m in [4, 6, 7, 9, 11]:
        if d > 30:
            return False

    return True

def perm(date):
    a = date[0]
    b = date[1]
    c = date[2]

    return [
            [a, b, c],
            [a, c, b],
            [b, a, c],
            [b, c, a],
            [c, a, b],
            [c, b, a]
        ]

def is18(f, b):
    df = f[0]
    mf = f[1]
    yf = f[2]

    for date in perm(b):
        if is_valid(date):
            db = date[0]
            mb = date[1]
            yb = date[2]
            if yf-yb > 18:
                return True
            if yf-yb == 18:
                if mf-mb > 0:
                    return True
                if mf-mb == 0 and df-db >= 0:
                    return True

    return False

if is18(a, b):
    print "YES"
else:
    print "NO"
