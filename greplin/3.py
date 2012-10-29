nums = [3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99]

def dec2bin(n):
    ret = []
    while n > 0:
        ret.append(n % 2)
        n /= 2
    return ret

def subsets(s):
    n = len(s)
    for i in xrange(1, 2**n):
        subset = []
        for j, b in enumerate(dec2bin(i)):
            if b == 1:
                subset.append(s[j])
        yield subset

ret = 0
for subset in subsets(nums):
    s = sorted(subset)
    if sum(subset[:-1]) == subset[-1]:
        ret += 1

print ret
