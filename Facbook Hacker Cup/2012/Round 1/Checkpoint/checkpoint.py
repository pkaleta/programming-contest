import sys
import copy

MAX_S = 10000005
values = {}

def precalc():
    prev_row = []
    for i in xrange(1, MAX_S+1):
        prev_row.append(i)
        values[i] = i
    for r in xrange(2, MAX_S):
        cur_row = [1]
        for c in xrange(1, MAX_S):
            val = prev_row[c] + cur_row[c-1]
            if val <= MAX_S and r + c < values[val]:
                values[val] = r + c
            cur_row.append(val)
            if val > MAX_S:
                break
        prev_row = copy.copy(cur_row)

def divisors(S):
    yield (1, S)
    i = 2
    while i*i <= S:
        if S % i == 0:
            yield (i, S / i)
        i += 1

precalc()

def solve(S):
    ret = float('inf')
    for a, b in divisors(S):
        ret = min(ret, values[a] + values[b])
    return ret

R = int(sys.stdin.readline())
for r in xrange(R):
    S = int(sys.stdin.readline())
    print "Case #%d: %d" % (r + 1, solve(S))


