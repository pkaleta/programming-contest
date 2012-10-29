import sys
import math

t = int(sys.stdin.readline())

def check(p1, p2):
    dx = p1[0] - p2[0]
    dy = p1[1] - p2[1]
    diff = math.sqrt(dx * dx + dy * dy)
    return (diff + p1[2] + p2[2]) / 2

for case in range(t):
    n = int(sys.stdin.readline())
    plants = []
    for i in range(n):
        plant = map(int, sys.stdin.readline().split())
        plants.append(plant)

    res = 0
    if n == 1:
        res = plants[0][2]
    elif n == 2:
        res = max(plants[0][2], plants[1][2])
    else:
        a = max(check(plants[0], plants[1]), plants[2][2])
        b = max(check(plants[0], plants[2]), plants[1][2])
        c = max(check(plants[1], plants[0]), plants[2][2])
        d = max(check(plants[1], plants[2]), plants[0][2])
        e = max(check(plants[2], plants[1]), plants[0][2])
        f = max(check(plants[2], plants[0]), plants[1][2])
        res = min(a, min(b, min(c, min(d, min(e, f)))))

    print "Case #%d: %.6f" % (case + 1, res)
