import sys

t = int(sys.stdin.readline())

def is_ugly(a):
    return (a % 2 == 0) or (a % 3 == 0) or (a % 5 == 0) or (a % 7 == 0)

global result

def evaluate(a):
    value = 0
    tmp = 0
    op = '+'
    for c in a:
        if c in ('+', '-'):
            if op == '+':
                value += tmp
            else:
                value -= tmp
            op = c
            tmp = 0
        else:
            tmp *= 10
            tmp += int(c)
    if op == '+':
        value += tmp
    else:
        value -= tmp
    return value


def test(a, b):
    if len(b) == 0:
        value = evaluate(a)
        if is_ugly(value):
            global result
            result += 1
    else:
        test(a + b[0], b[1:])
        test(a + '+' + b[0], b[1:])
        test(a + '-' + b[0], b[1:])


for c in range(t):
    global result
    n = sys.stdin.readline().strip()
    result = 0
    test(n[0], n[1:])
    print "Case #%d: %d" %(c + 1, result)
