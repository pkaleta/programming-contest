def lcm(a, b):
    return a * b / gcd(a, b)

def gcd(a, b):
    while a > 0:
        tmp = a
        a = b % a
        b = tmp
    return tmp


print reduce(lcm, range(1,21))
