import sys

n = sys.stdin.readline().strip()
a = ""
b = ""
x = n.split('.')

def chunks(l, n):
    l = l[::-1]
    ret = []
    for i in xrange(0, len(l), n):
        ret.append(l[i:i+n][::-1])
    return ret[::-1]

if len(x) == 2:
    a, b = x
    b = (b+'00')[:2]
else:
    a = x[0]
    b = '00'

minus = False
if a[0] == '-':
    a = a[1:]
    minus = True

ret = ','.join(chunks(a, 3)) + '.' + b

if minus:
    print "($%s)" % ret
else:
    print "$%s" % ret
