n = 10000

print n
a = []
for i in xrange(n):
    a.append(1000000000-i)

print ' '.join(map(str, a))
