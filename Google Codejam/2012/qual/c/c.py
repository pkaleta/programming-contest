import sys
from collections import defaultdict

MAX = 2000005

def recycled(number, A, B):
    digits = str(number)
    n = len(digits)
    result = []

    for i in xrange(1, n):
        prefix, suffix = digits[:i], digits[i:]
        rec = int(suffix + prefix)
        if A <= rec <= B and number < rec and suffix[0] != '0':
            result.append(rec)

    return set(result)


def recycled_count(A, B, recs):
    recycled_pairs = {}
    count = 0

    for number in xrange(A, B + 1):
        if number not in recycled_pairs:
            size = 0
            for rec in recs[number]:
                if A <= rec <= B:
                    size += 1
                    recycled_pairs[rec] = True
            count += size * (size + 1) // 2

    return count

if __name__ == "__main__":
    recs = {}
    for i in xrange(MAX):
        recs[i] = recycled(i, 1, MAX)
    T = int(sys.stdin.readline())
    for t in xrange(T):
        A, B = map(int, sys.stdin.readline().split())
        print "Case #%d: %d" % (t + 1, recycled_count(A, B, recs))
