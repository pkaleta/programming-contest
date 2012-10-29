def is_prime(n):
    return not any(n % k == 0 for k in xrange(2, n))

prime_counter = 0
n = 1
while prime_counter < 10001:
    n += 1
    if is_prime(n):
        prime_counter += 1
print n
