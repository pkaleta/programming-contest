import sys

H, W = map(int, sys.stdin.readline().split())
m = []
for i in xrange(H):
    tmp = sys.stdin.readline()[:-1]
    line = []
    for j in xrange(W):
        line.append(tmp[j])
    m.append(line)

maxSize = 30

def createEmptyPiece():
    return [['*' for i in xrange(maxSize)] for i in xrange(maxSize)]

def createPiece(x, y, w, h):
    piece = createEmptyPiece()
    for i in xrange(y, y + h):
        for j in xrange(x, x + w):
            piece[i-y][j-x] = m[i][j]
    return piece

def rot90(piece, w, h):
    rotated = createEmptyPiece()
    for y in xrange(h):
        for x in xrange(w):
            rotated[x][h-1-y] = piece[y][x]
    return rotated

def rot180(piece, w, h):
    rotated = createEmptyPiece()
    for y in xrange(h):
        for x in xrange(w):
            rotated[h-1-y][w-1-x] = piece[y][x]
    return rotated

def rot270(piece, w, h):
    rotated = createEmptyPiece()
    for y in xrange(h):
        for x in xrange(w):
            rotated[w-1-x][y] = piece[y][x]
    return rotated

def eql(p1, p2):
    for i in xrange(maxSize):
        for j in xrange(maxSize):
            if p1[i][j] != p2[i][j]:
                return False
    return True;

def equal(x1, y1, x2, y2, w, h):
    p1 = createPiece(x1, y1, w, h)
    p2 = createPiece(x2, y2, w, h)
    return eql(p1, p2) or eql(p1, rot90(p2, w, h)) or eql(p1, rot180(p2, w, h)) or eql(p1, rot270(p2, w, h))

count = 0
minw = W
minh = H

for h in xrange(1, H+1):
    for w in xrange(1, W+1):
        if H % h == 0 and W % w == 0:
            isEqual = False
            for y1 in xrange(H-h+1):
                for x1 in xrange(W-w+1):
                    for y2 in xrange(H-h+1):
                        for x2 in xrange(W-w+1):
                            if y1+h <= y2 or x1+w <= x2:
                                if equal(x1, y1, x2, y2, w, h):
                                    isEqual = True
            if not isEqual:
                count += 1
                if w*h < minw*minh or (w*h == minw*minh and h < minh):
                    minw = w
                    minh = h

print count
print minh, minw
