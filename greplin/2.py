def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def fib(n):
    a = 1
    b = 1
    while b < n or not is_prime(b):
        tmp = a
        a = b
        b += tmp
    return b

def prime_divs_sum(n):
    ret = 0
    i = 2
    while i * i <= n:
        if n % i == 0:
            if is_prime(i):
                ret += i
            if i != n / i and is_prime(n / i):
                ret += n/i
        i += 1
    return ret

print prime_divs_sum(fib(227000)+1)
