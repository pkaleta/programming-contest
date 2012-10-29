from math import sqrt

i = 1
triangle = 1
n = 0
while True:
    for j in range(1, sqrt(triangle + 1)):
        if (triangle % j == 0):
            n += 2
    if n > 500:
        print triangle
        break
    i += 1
    triangle += i
    n = 0
