import sys

n = int(sys.stdin.readline())
MOD = 1000000007

nom = 1
den = 1

for i in xrange(1, n):
    nom *= n+i
    den *= i
    if nom % den == 0:
        nom /= den
        den = 1
        nom %= MOD

tmp = nom % MOD
print tmp + tmp - n
