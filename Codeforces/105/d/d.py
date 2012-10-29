import sys

w, b = map(int, sys.stdin.readline().split())

dp = {}

def solve(w, b):
    if w == 0:
        return 0.0
    if b == 0:
        return 1.0
    if b < 0:
        return 0.0
    if (w, b) in dp:
        return dp[(w, b)]
    ret =  w/(w+b)
    if b > 1:
        ret += b/(w+b) * (b-1)/(w+b-1) * (w/(w+b-2) * solve(w-1, b-2) + (b-2)/(w+b-2) * solve(w, b-3))
    dp[(w, b)] = ret
    return ret

print "%.9f" % solve(float(w), float(b))
