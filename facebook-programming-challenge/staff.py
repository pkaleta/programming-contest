from collections import defaultdict
import sys

branch = map(int, list(sys.stdin.readline().strip()))

n = len(branch)


def initialize(branch):
    weighted_mass_sum = defaultdict(lambda: \
        defaultdict(lambda: defaultdict(int)))
    mass_sum = defaultdict(lambda: defaultdict(int))

    for begin in xrange(n):
        for initial_dist in xrange(n):
            current_weighted_mass_sum = 0
            current_mass_sum = 0
            for i in xrange(begin, n):
                length = i - begin + 1

                current_mass_sum += branch[i]
                mass_sum[begin][length] = current_mass_sum

                dist = initial_dist + length

                current_weighted_mass_sum += branch[i] * dist
                weighted_mass_sum[begin][length][initial_dist + 1] = \
                    current_weighted_mass_sum

    return weighted_mass_sum, mass_sum


weighted_mass_sum, mass_sum = initialize(branch)
rev_weighted_mass_sum, rev_mass_sum = initialize(branch[::-1])


def check(a, b, length, rev_weighted_mass_sum, weighted_mass_sum, mass_sum):
    # if a == 0 and b == 8:
    #     print "checking:", a, b, length
    #     print "*******", weighted_mass_sum[a][length][1]
    #     print "*******", weighted_mass_sum[b][length][length + 1]
    rev_left_weighted_mass_sum = rev_weighted_mass_sum[a][length][0]
    rev_right_weighted_mass_sum = rev_weighted_mass_sum[b][length][length]

    left_weighted_mass_sum = weighted_mass_sum[a][length][0]
    right_weighted_mass_sum = weighted_mass_sum[b][length][length]
    left_mass_sum = mass_sum[a][length]
    right_mass_sum = mass_sum[b][length]
    staff_weighted_mass_sum = \
        float(left_weighted_mass_sum + right_weighted_mass_sum)
    staff_mass_sum = float(left_mass_sum + right_mass_sum)
    center = staff_weighted_mass_sum / staff_mass_sum
    if center == float(length) / 2.:
#        print "*********", a, b, length
        return True
    return False


def solve():
    for length in xrange(n, 0, -1):
        for a in xrange(n):
            for b in xrange(n):
                if a in weighted_mass_sum and length in weighted_mass_sum[a] and \
                   b in weighted_mass_sum and length in weighted_mass_sum[b]:
                    if check(a, b, length, rev_weighted_mass_sum,
                             weighted_mass_sum, mass_sum):
                        return a, b, length


if __name__ == "__main__":
    a, b, length = solve()
    print a, b, length
