import sys

fs = map(lambda s: s.strip(), sys.stdin.readlines())
disks = {}

def add(ps, folder):
    if len(ps) == 1:
        first = ps[0]
        if not folder.has_key(first):
            folder[first] = True
    elif len(ps) > 0:
        first = ps[0]
        if not folder.has_key(first):
            folder[first] = {}
        add(ps[1:], folder[first])

def build():
    for f in fs:
        ps = f.split('\\')
        add(ps, disks)

def calc(folder):
    ds = 0
    fs = 0
    for k, v in folder.items():
        if v == True:
            fs += 1
        else:
            ds1, fs1 = calc(v)
            ds += ds1+1
            fs += fs1
    return (ds, fs)

maxd = 0
maxf = 0
build()
for k1, v1 in disks.items():
    for k, v in v1.items():
        ds, fs = calc(v)
        maxd = max(maxd, ds)
        maxf = max(maxf, fs)

print maxd, maxf
