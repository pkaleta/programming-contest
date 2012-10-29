triangle = []

for line in open('triangle.txt').readlines():
    line.replace('\r\n', '')
    triangle.append(map(int, line.split(' ')))
    triangle[-1].extend([0] * 200)

for i in range(1, len(triangle)):
    for j in range(i + 1):
        try:
            triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1])
        except IndexError:
            triangle[i][j] += triangle[i - 1][j]

print max(triangle[-1])

