import sys

n, k = map(int, sys.stdin.readline().split())
stripe = sys.stdin.readline().strip()


def get_any_but(not_allowed):
    for i in xrange(0, k):
        c = chr(ord('A') + i)
        if c not in not_allowed:
            return c


def solve(s, l, r):
    if r - l + 1 <= 2:
        return (0, list(s[l: r + 1]))

    m = (l + r) / 2
    lchange, lstripe = solve(s, l, m)
    rchange, rstripe = solve(s, m + 1, r)
    change = lchange + rchange
    if lstripe[-1] == rstripe[0]:
        lstripe[-1] = get_any_but([lstripe[-2], rstripe[0]])
        change += 1

    return (change, lstripe + rstripe)

change, result = solve(stripe, 0, len(stripe) - 1)
print change, ''.join(result)
