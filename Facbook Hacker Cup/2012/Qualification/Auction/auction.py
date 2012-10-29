import sys

T = int(sys.stdin.readline())
for t in xrange(1, T+1):
    n, pi, wi, m, k, a, b, c, d = map(int, sys.stdin.readline().split())
    bargains = {(pi, wi) : 1}
    terrible = {(pi, wi) : 1}
    for i in xrange(min(n-1, 5000000)):
        pi = ((a * pi + b) % m) + 1
        wi = ((c * wi + d) % k) + 1
        is_bargain = True
        is_terrible = True
        # bargains_to_remove = set([])
        # terrible_to_remove = set([])

        for (pj, wj) in bargains.keys():
            if (pi < pj and wi <= wj) or (pi <= pj and wi < wj):
                del bargains[(pj, wj)]
#                bargains_to_remove.add((pj, wj))
            if (pj < pi and wj <= wi) or (pj <= pi and wj < wi):
                is_bargain = False

        for (pj, wj) in terrible.keys():
            if (pi < pj and wi <= wj) or (pi <= pj and wi < wj):
                is_terrible = False
            if (pj < pi and wj <= wi) or (pj <= pi and wj < wi):
                del terrible[(pj, wj)]
#                terrible_to_remove.add((pj, wj))

        # bargains = bargains.difference(bargains_to_remove)
        # terrible = terrible.difference(terrible_to_remove)

        if is_bargain:
            if bargains.has_key((pi, wi)):
                bargains[(pi, wi)] += 1
            else:
                bargains[(pi, wi)] = 1
        if is_terrible:
            if terrible.has_key((pi, wi)):
                terrible[(pi, wi)] += 1
            else:
                terrible[(pi, wi)] = 1

    print "Case #%d: %d %d" % (t, sum(terrible.values()), sum(bargains.values()))
