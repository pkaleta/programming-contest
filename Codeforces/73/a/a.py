import sys

cs = sys.stdin.readline().split()

INF = float('inf')
notes = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"]
n = len(notes)
d = {}

for n1 in notes:
    d[n1] = {}
    for n2 in notes:
        if n1 == n2:
            d[n1][n2] = 0
        else:
            d[n1][n2] = INF

for i in xrange(n):
    dist = 1
    j = (i+1) % n
    while j != i:
        d[notes[i]][notes[j]] = min( d[notes[i]][notes[j]], dist )
        j = (j+1) % n
        dist += 1

#for i in xrange(n):
#    dist = 1
#    if i == 0:
#        j = n-1
#    else:
#        j = i-1
#    while j != i:
#        d[notes[i]][notes[j]] = min( d[notes[i]][notes[j]], dist )
#        if j == 0:
#            j = n-1
#        else:
#            j = j-1
#        dist += 1


#print d[cs[0]][cs[1]], d[cs[1]][cs[2]]
#print d[cs[0]][cs[2]], d[cs[2]][cs[1]]
#print d[cs[1]][cs[0]], d[cs[0]][cs[2]]
#print d[cs[1]][cs[2]], d[cs[2]][cs[0]]
#print d[cs[2]][cs[0]], d[cs[0]][cs[1]]
#print d[cs[2]][cs[1]], d[cs[1]][cs[0]]

if (d[cs[0]][cs[1]] == 4 and d[cs[1]][cs[2]] == 3) or \
    (d[cs[0]][cs[2]] == 4 and d[cs[2]][cs[1]] == 3) or \
    (d[cs[1]][cs[0]] == 4 and d[cs[0]][cs[2]] == 3) or \
    (d[cs[1]][cs[2]] == 4 and d[cs[2]][cs[0]] == 3) or \
    (d[cs[2]][cs[0]] == 4 and d[cs[0]][cs[1]] == 3) or \
    (d[cs[2]][cs[1]] == 4 and d[cs[1]][cs[0]] == 3):
    print 'major'
elif (d[cs[0]][cs[1]] == 3 and d[cs[1]][cs[2]] == 4) or \
    (d[cs[0]][cs[2]] == 3 and d[cs[2]][cs[1]] == 4) or \
    (d[cs[1]][cs[0]] == 3 and d[cs[0]][cs[2]] == 4) or \
    (d[cs[1]][cs[2]] == 3 and d[cs[2]][cs[0]] == 4) or \
    (d[cs[2]][cs[0]] == 3 and d[cs[0]][cs[1]] == 4) or \
    (d[cs[2]][cs[1]] == 3 and d[cs[1]][cs[0]] == 4):
    print 'minor'
else:
    print 'strange'

