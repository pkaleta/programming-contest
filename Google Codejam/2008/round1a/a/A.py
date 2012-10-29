import sys

t = int(sys.stdin.readline())

def mul(v1, v2):
    return sum([v1[i] * v2[i] for i in range(len(v1))])

for c in range(t):
    n = int(sys.stdin.readline())
    v1 = [int(x) for x in sys.stdin.readline().split()]
    v2 = [int(x) for x in sys.stdin.readline().split()]
    result = mul(v1, v2)
    v1.sort()
    v2.sort()
    v2.reverse()
    print "Case #%d: %d" %(c + 1, mul(v1, v2))
