import sys

p, d = [x.strip() for x in sys.stdin.readline().split()]

result = p


def get_price():
    result = p
    for i in xrange(1, len(p) + 1):
        price = p[:-i] + '9' * i

        if int(price) > int(p) and i < len(p) and int(p[:-i]) > 1:
            price = str(int(p[:-i]) - 1) + '9' * i

        if int(price) >= int(p) - int(d) and int(price) <= int(p):
            result = price
            continue

    return result


print get_price()
