import sys

t = int(sys.stdin.readline())

perms = []

def permute(alist, level=0):
    index, copy, printing = level, list(alist), level+1 == len(alist)

    while 1:
        if printing:
            perms.append(map(str, copy))
#            print ''.join(map(str, copy)), copy
        else:
            permute(copy, 1+level);

        if index != 0:
            copy[index-1], copy[index] = copy[index], copy[index-1]

        index -= 1
        if index < 0:
            break

for case in range(t):
    p, q = map(int, sys.stdin.readline().split())
    cells = map(int, sys.stdin.readline().split())
    perms = []

    permute(cells)
    result = -1

    for perm in perms:
        free = [False for _ in range(p + 1)]
        tmp = 0
        for c in map(int, perm):
            free[c] = True
            i = c - 1
            while i > 0 and not free[i]:
                tmp += 1
                i -= 1
            i = c + 1
            while i <= p and not free[i]:
                tmp += 1
                i += 1
        if result == -1:
            result = tmp
        else:
            result = min(result, tmp)

    print "Case #%d: %d" % (case + 1, result)

#    cells.sort()
#    a = 1
#    b = p
#    result = 0
#    while 1:
#        result += b - a
#        if len(cells) == 1:
#            break
#        else:
#            left = cells[0] - a
#            right = b - cells[len(cells) - 1]
#            if right > left:
#                b = cells[len(cells) - 1] - 1
#                cells = cells[0:-1]
#            else:
#                a = cells[0] + 1
#                cells = cells[1:]
#
