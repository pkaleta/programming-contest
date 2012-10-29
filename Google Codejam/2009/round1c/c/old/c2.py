import sys

t = int(sys.stdin.readline())

for case in range(t):
    p, q = map(int, sys.stdin.readline().split())
    cells = map(int, sys.stdin.readline().split())

    cells.sort()
    a = 1
    b = p
    result = 0
    while 1:
        result += b - a
        if len(cells) == 1:
            break
        else:
            left = cells[0] - a
            right = b - cells[len(cells) - 1]
            if right > left:
                print cells[len(cells) - 1]
                b = cells[len(cells) - 1] - 1
                cells = cells[0:-1]
            else:
                print cells[0]
                a = cells[0] + 1
                cells = cells[1:]


    print "Case #%d: %d" % (case + 1, result)
