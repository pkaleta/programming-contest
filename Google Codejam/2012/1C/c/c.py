import sys
from copy import deepcopy

T = int(sys.stdin.readline())

def get(boxes, toys, box_index, min_toy_index, max_toy_index):
    box_count, box_type = boxes[box_index]
    ret = 0
    new_toys = deepcopy(toys)

    #    print "###########", box_type
    last = -1
    for i in xrange(min_toy_index, max_toy_index):
        toy_count, toy_type = toys[i]
        #        print "*********", box_type, toy_type, toy_count
        if box_type == toy_type:
            count = min(toy_count, box_count)
            ret += count
            box_count -= count
            new_toys[i][0] -= count
            last = i
            if box_count == 0:
                break
    return ret, new_toys, last


def solve(box_index, start, boxes, toys, N, M):
    if box_index >= N:
        return 0
    if start >= M:
        return 0

    #    print "BOX: ", box_index
    if box_index == N-1:
        #        print "******** KONIEC: ", start, M, get(boxes, toys, box_index, start, M)
        ret, new_toys, last = get(boxes, toys, box_index, start, M)
        return ret
    else:
        max_ret = 0
        for i in xrange(start, M+1):
            ret, new_toys, last = get(boxes, toys, box_index, start, i)
            #            print "***********", start, i
            if new_toys[last][0] != toys[last][0]:
                cur1 = ret + solve(box_index + 1, last, boxes, new_toys, N, M)
            else:
                cur1 = 0
            cur = ret + solve(box_index + 1, i, boxes, toys, N, M)
            max_ret = max(cur, cur1, max_ret)

        return max_ret


for t in xrange(T):
    N, M = map(int, sys.stdin.readline().split())
    a = map(int, sys.stdin.readline().split())
    boxes = [[a[i], a[i+1]] for i in xrange(0, len(a), 2)]
    b = map(int, sys.stdin.readline().split())
    toys = [[b[i], b[i+1]] for i in xrange(0, len(b), 2)]

    ret = solve(0, 0, boxes, toys, N, M)

    #    print get(boxes, toys, 0, 0, 2)

    print "Case #%d: %d" % (t + 1, ret)
