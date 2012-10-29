import sys

hp = {}

def convert(n, b):
    res = []
    while n:
        res.append(n % b)
        n /= b
    return res[::-1]

def add(x, y, b):
    maxlen = max(len(x), len(y))
    revx = [0 for _ in range(maxlen)]
    res = [0 for _ in range(maxlen)]

    for i in range(len(x) - 1, -1, -1):
        revx[len(x) - 1 - i] = x[i]

    for i in range(len(y) - 1, -1, -1):
        res[len(y) - 1 - i] = y[i]

    for (i, d) in enumerate(revx):
        res[i] += d
        rem = 0
        if (res[i] >= b):
            rem = res[i] / b
            res[i] %= b

        if (rem > 0):
            if (len(res) - 1 < i + 1):
                res.append(0)
            res[i + 1] += rem

    return res[::-1]

def update(n, b):
    res = []
    for d in n:
        res = add(res, convert(d * d, b), b)
    return res

def value(n):
    return ''.join(map(str, n))

def is_happy(n, b):
    if hp.has_key((n, b)):
        return hp[(n, b)]
    n = convert(n, b)
    used = {}
    while (len(n) > 1 or n[0] != 1):
        used[value(n)] = True
        n = update(n, b)
        if used.has_key(value(n)):
            hp[(value(n), b)] = False
            return False
    hp[(value(n), b)] = True
    return True

t = int(sys.stdin.readline())

for case in range(t):
    bases = map(int, sys.stdin.readline().split())

    n = 2
    while True:
        happy = True
        for b in bases:
            if not is_happy(n, b):
                happy = False
                break;
        if happy:
            break
        n += 1

    print "Case #%d: %d" % (case + 1, n)

