#!/usr/bin/env python

import sys
import pprint
from string import uppercase
from heapq import heappush, heappop

pp = pprint.PrettyPrinter(width=40)

def swap(tpl, i):
    return tpl[:i] + (tpl[i+1], tpl[i]) + tpl[i+2:]

def dist(tpl):
    return sum(max(0, x-i) for i, x in enumerate(tpl))

no_cases = input()
for case in xrange(1, no_cases+1):
    case_size = input()
    indices = tuple(('1'+sys.stdin.readline()).rindex('1')-1 for _ in xrange(case_size))
    queue = [(0, dist(indices), indices)]
    used = set()
    while queue:
        n, d, tpl = heappop(queue)
        if d == 0:
            answer = n
            break
        for i in xrange(case_size-1):
            s = swap(tpl, i)
            dd = dist(s)
            if dd <= d and s not in used:
                used.add(s)
                heappush(queue, (n+1, dd, s))
    print 'Case #%d: %d' % (case, answer)
