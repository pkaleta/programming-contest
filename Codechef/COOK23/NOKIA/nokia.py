import sys

T = int(sys.stdin.readline())


# def score(p):
#     n = len(p)
#     sol = [False for i in xrange(0, n + 2)]
#     sol[0] = sol[n + 1] = True
#     res = 0

#     for s in p:
#         left = s - 1
#         right = s + 1
#         while not sol[left]:
#             left -= 1
#         while not sol[right]:
#             right += 1
#         res += s - left + right - s
#         sol[s] = True

#     return res


def calc_min_len(l, r):
    if l + 1 == r:
        return 0
    if l >= r:
        return 0

    m = (l + r) // 2
    return m - l + r - m + calc_min_len(l, m) + calc_min_len(m, r)


def calc_max_len(n):
    return sum(xrange(2, N + 2))


for t in xrange(T):
    N, M = map(int, sys.stdin.readline().split())

    min_len = calc_min_len(1, N + 2)
    max_len = calc_max_len(N)

    if M < min_len:
        print -1
    elif M > max_len:
        print M - max_len
    else:
        print 0
