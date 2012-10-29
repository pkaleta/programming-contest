import sys

t = sys.stdin.readline()[:-1]
a, b = sys.stdin.readline().split()

card1, col1 = a
card2, col2 = b

d = {'6':6, '7':7, '8':8, '9':9, 'T':10, 'J':11, 'Q':12, 'K':13, 'A':14}

if col1 == col2:
    if d[card1] > d[card2]:
        print 'YES'
    else:
        print 'NO'
else:
    if t == col1:
        print 'YES'
    else:
        print 'NO'

