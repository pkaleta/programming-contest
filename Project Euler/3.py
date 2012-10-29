max_prime = 2
n = 600851475143
tmp = 2
while n > 1:
    if n % tmp == 0:
        n /= tmp
        if tmp % 2 != 0 and tmp > max_prime:
            max_prime = tmp
        print tmp
    else:
        tmp += 1
print max_prime
