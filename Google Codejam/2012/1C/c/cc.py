import sys

def solve(boxes, toys, n, m):
    if n < 0 or m < 0:
        return 0

    #    print boxes[:n+1], n, toys[:m+1], m

    box_count, box_type = boxes[n]
    toy_count, toy_type = toys[m]

    if box_type == toy_type:
        count = min(box_count, toy_count)
        boxes[n][0] -= count
        toys[m][0] -= count
        ret = 0
        if boxes[n][0] > 0:
            ret = max(ret, count + solve(boxes, toys, n, m-1))
        if toys[m][0] > 0:
            ret = max(ret, count + solve(boxes, toys, n-1, m))
        ret = max(ret, count + solve(boxes, toys, n-1, m-1))
        boxes[n][0] += count
        toys[m][0] += count
        return ret
    else:
        return max(solve(boxes, toys, n-1, m), solve(boxes, toys, n, m-1))

T = int(sys.stdin.readline())
for t in xrange(T):
    N, M = map(int, sys.stdin.readline().split())
    a = map(int, sys.stdin.readline().split())
    boxes = [[a[i], a[i+1]] for i in xrange(0, len(a), 2)]
    b = map(int, sys.stdin.readline().split())
    toys = [[b[i], b[i+1]] for i in xrange(0, len(b), 2)]


    print "Case #%d: %d" % (t + 1, solve(boxes, toys, N-1, M-1))
