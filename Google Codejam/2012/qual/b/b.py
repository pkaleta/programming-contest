import sys

T = int(sys.stdin.readline())

def get_best_result(total_points, limit):
    if total_points % 3 == 0:
        mx = total_points // 3
        if mx >= limit:
            return (True, False)
        elif mx + 1 >= limit and mx <= 9 and total_points > 0:
            return (True, True)
        else:
            return (False, False)
    elif total_points % 3 == 1:
        mx = total_points // 3 + 1
        if mx >= limit:
            return (True, False)
        else:
            return (False, False)
    else:
        mx = total_points // 3 + 1
        if mx >= limit:
            return (True, False)
        elif mx + 1 >= limit and mx <= 9:
            return (True, True)
        else:
            return (False, False)


def solve(N, S, p, s):
    s = sorted(s)[::-1]
    result = 0
    surprising = 0
    for i in xrange(N):
        is_better, is_surprising = get_best_result(s[i], p)
        if is_better:
            if is_surprising and surprising == S:
                break
            result += 1
            surprising += is_surprising
        else:
            break
    return result

if __name__ == "__main__":
    for t in xrange(T):
        line = map(int, sys.stdin.readline().split())
        N = line[0]
        S = line[1]
        p = line[2]
        s = line[3:]
        print "Case #%d: %d" % (t + 1, solve(N, S, p, s))
