import sys

def readPerson(line):
    colon = line.find(':')
    dot = line.find('.')
    if colon == -1 or dot < colon:
        return (line[dot+1:], (line[:dot], []))
    name = line[:colon]
    workers = []
    line = line[colon+1:]
    while (True):
        line, w = readPerson(line)
        workers.append(w)
        if (line[0] != ','):
            break
        line = line[1:]

    return (line[1:], (name, workers))

line = sys.stdin.readline()[:-1]
_, root = readPerson(line)


result = 0
def calc(n):
    name, workers = n

    d = {}
    for w in workers:
        x = calc(w)
        for (k, v) in x.items():
            if not d.has_key(k):
                d[k] = 0
            d[k] += v

    global result
    if not d.has_key(name):
        d[name] = 0
    result += d[name]
    d[name] += 1

    return d

calc(root)

print result
