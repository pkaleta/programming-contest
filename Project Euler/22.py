names = open('names.txt').read().replace('\"', '').split(',')
names.sort(lambda x, y: cmp(x, y))

total = 0
for i, name in enumerate(names):
    total += sum(map(lambda x: ord(x) - ord('A') + 1, list(name))) * (i + 1)
print total
