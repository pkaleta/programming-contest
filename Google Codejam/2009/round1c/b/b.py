import sys
import math

t = int(sys.stdin.readline())

for case in range(t):
    swarm = []
    n = int(sys.stdin.readline())
    sx, sy, sz, vx, vy, vz = [0 for _ in range(6)]

    for i in range(n):
        fly = map(int, sys.stdin.readline().strip().split())
        swarm.append(fly)
        sx += fly[0]
        sy += fly[1]
        sz += fly[2]

        vx += fly[3]
        vy += fly[4]
        vz += fly[5]



    print "Case #%d: %.8f %.8f" % (case + 1, math.sqrt(prev), time)
