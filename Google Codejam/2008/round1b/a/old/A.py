import sys

t = int(sys.stdin.readline())

for z in range(t):
    n, a, b, c, d, x, y, m = [int(x) for x in sys.stdin.readline().split()]
    rem = []
    for i in range(3):
        rem.append([])
        for j in range(3):
            rem[i].append(0)
    result = 0

    for i in range(n):
        rem[x%3][y%3] += 1
        x = (a * x + b) % m
        y = (c * y + d) % m

    for i in range(3):
        for j in range(3):
            result += rem[i][j] * (rem[i][j] - 1) * (rem[i][j] - 2) / 6

    for i in range(3):
        result += rem[i][0] * rem[i][1] * rem[i][2]
        result += rem[0][i] * rem[1][i] * rem[2][i]

    for i in range(3):
        for j in range(3):
            for k in range(3):
                if i != j and i != k and j != k:
                    result += rem[0][i] * rem[1][j] * rem[2][k]

    print "Case #%d: %d" %(z + 1, result)
