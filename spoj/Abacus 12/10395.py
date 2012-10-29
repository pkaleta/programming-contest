import sys

# MAXN = 1000005
# d = [0 for i in xrange(MAXN)]

# def is_prime(n):
#     i = 2
#     while i * i <= n:
#         if n % i == 0:
#             return False
#         i += 1
#     return True

# for i in xrange(1, MAXN):
#     s = 0
#     j = 1
#     while j * j <= i:
#         if i % j == 0:
#             s += j
#             if i / j != j:
#                 s += i/j
#         j += 1
#     d[i] = d[i-1]
#     if is_prime(s):
#         print i
#         d[i] += 1

T = int(sys.stdin.readline())

K = [2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921]

for t in xrange(T):
    a, b = map(int, sys.stdin.readline().split())
    ret = 0
    for i in xrange(len(K)):
        if a <= K[i] <= b:
            ret += 1
    print ret
