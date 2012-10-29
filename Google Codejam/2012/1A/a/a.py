import sys

T = int(sys.stdin.readline())

for t in xrange(T):
    A, B = map(int, sys.stdin.readline().split())
    p = map(float, sys.stdin.readline().split()) + [0.0]

    ret = B + 2
    prob_all_prev_ok = p[0]
    prob = 1.0 - p[0]
    for i in xrange(1, A+1):
        backspaces = A - i
        cur = prob * (A + 2 * B + 2 - 2 * i) + (1.0 - prob) * (A + B - 2 * i + 1)
        ret = min(ret, cur)
        prob += prob_all_prev_ok * (1.0-p[i])
        prob_all_prev_ok *= p[i]
    print "Case #%d: %.6f" % (t + 1, ret)
