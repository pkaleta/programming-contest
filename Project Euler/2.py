a = 1
b = 1
sum = 0;
while (b < 4000000):
    tmp = a
    a = b
    b += tmp
    if b % 2 == 0:
        sum += b
print sum
