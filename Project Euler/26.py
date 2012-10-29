def find(l, x):
    for i in xrange(len(l)):
        if x == l[i]:
            return i

def recurring_cycle_len(d):
    num = 1
    s = []
    p = 10 ** (len(str(d)))
    while True:
        s.append((p * num) // d)
        num = (p * num) % d
        if s[-1] in s[:-1]:
            # print '***', s
            # print '###', ''.join(map(str, s[find(s, s[-1]):-1]))
            return len(''.join(map(str, s[find(s, s[-1]):-1])))
        if s[-1] == '0':
            return 0

max_len = 0
for d in xrange(2, 1000):
    l = recurring_cycle_len(d)
#    print d, l
    if l > max_len:
        max_len = l
        dd = d

print dd
