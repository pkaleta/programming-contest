import sys
import re

n = int(sys.stdin.readline())
s = [0 for i in xrange(n)]
name = [None for i in xrange(n)]

def category(number):
    number = re.sub("-", "", number)
    taxi = True
    pizza = True
    for i in xrange(len(number)):
        d = number[i]
        if d != number[0]:
            taxi = False
        if i > 0 and number[i] >= number[i-1]:
            pizza = False
    if taxi:
        return 0
    if pizza:
        return 1
    return 2

d = {}
max_cat = [0, 0, 0]

for i in xrange(n):
    a, b = sys.stdin.readline().split()
    s[i] = int(a.strip())
    name[i] = b.strip()
    d[name[i]] = {0: 0, 1: 0, 2: 0}
    for j in xrange(s[i]):
        number = sys.stdin.readline().strip()
        cat = category(number)
        d[name[i]][cat] += 1
        max_cat[cat] = max(max_cat[cat], d[name[i]][cat])

max_names = [[], [], []]
for i in xrange(n):
    for c in xrange(3):
        if d[name[i]][c] == max_cat[c]:
            max_names[c].append(name[i])

print "If you want to call a taxi, you should call: %s." % (', '.join(max_names[0]))
print "If you want to order a pizza, you should call: %s." % (', '.join(max_names[1]))
print "If you want to go to a cafe with a wonderful girl, you should call: %s." % (', '.join(max_names[2]))
