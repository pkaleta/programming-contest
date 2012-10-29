h = {}
max_length = 0
max_number = 0

for i in range(1, 1000000):
    n = i
    length = 1
    stack = [i]
    while n != 1:
        try:
            length += h[n] - 1
            break
        except KeyError:
            length += 1
            if n % 2 == 0:
                n /= 2
            else:
                n = 3 * n + 1
            stack.append(n)
    for j in range(len(stack)):
        h[stack[j]] = length - j
    if length > max_length:
        max_length = length
        max_number = i
print max_number, max_length
