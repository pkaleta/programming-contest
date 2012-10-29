#!/usr/bin/env python

import sys

no_cases = input()

for case in xrange(1, no_cases+1):
    digits = [int(digit) for digit in sys.stdin.readline().strip()]
    if digits == list(sorted(digits, reverse=True)):
        leader = min(d for d in digits if d > 0)
        rest = list(digits)
        rest.remove(leader)
        rest.sort()
        answer = [leader, 0] + rest
    elif digits[-2] < digits[-1]:
        answer = digits[:-2] + [digits[-1], digits[-2]]
    else:
        i, j = -2, -1
        while digits[i] >= digits[j]:
            i -= 1; j -= 1
        tail = digits[i:]
        tailhead = min(k for k in tail if k > tail[0])
        tail.remove(tailhead)
        tail.sort()
        answer = digits[:i] + [tailhead] + tail
    print 'Case #%d: %s' % (case, ''.join(str(d) for d in answer))
