is_prime = {1 : False}
sum = 0

for i in range(2, 2000000):
    print i
    try:
        is_prime[i]
    except KeyError:
        is_prime[i] = True
        sum += i
        j = 2 * i
        while j < 2000000:
            is_prime[j] = False
            j += i
print sum
