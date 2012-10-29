d = {}
total = 0
for i in range(1, 10000):
    if i in d.keys():
        sum_a = d[i]
    else:
        sum_a = sum(j for j in range(1, i) if i % j == 0)
        d[i] = sum_a
    if sum_a in d.keys():
        sum_b = d[sum_a]
    else:
        sum_b = sum(j for j in range(1, sum_a) if sum_a % j == 0)
        d[sum_a] = sum_b
    if sum_b == i and sum_a != i:
        print i
        total += i
print total
