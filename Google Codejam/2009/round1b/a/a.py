import sys
import re

class Node:
    def __init__(self):
        self.name = None
        self.value = None
        self.left = None
        self.right = None


n = int(sys.stdin.readline())

def child(s, start):
    end = start + 1
    count = 1
    while count > 0:
        if s[end] == "(":
            count += 1
        if s[end] == ")":
            count -= 1
        end += 1
    return (s[start : end], end)


def children(s):
    lstart = s.find('(')
    (left, rstart) = child(s, lstart)
    (right, _) = child(s, rstart)
    return (left, right)


def read(s):
    string = s[1:-1]
    node = Node()
    node.value = float(re.match("(\d+\.\d+)(\w*)", string).group(1))
    node.name = re.match("(\d+\.\d+)(\w*)", string).group(2)

    if node.name is '':
        node.name = None
    else:
        (left, right) = children(string)
        node.left = read(left)
        node.right = read(right)
    return node

def traverse(node, animal):
    if node is None:
        return 1.0
    else:
        if node.name in animal:
            return node.value * traverse(node.left, animal)
        else:
            return node.value * traverse(node.right, animal)

for t in range(n):
    l = int(sys.stdin.readline())
    lines = []
    for i in range(l):
        lines.append(sys.stdin.readline().strip())
    string = ''.join(lines)
    string = re.sub("\s+", "", string.strip())
    node = read(string)

    print "Case #%d: " % (t + 1)
    a = int(sys.stdin.readline())
    for i in range(a):
        animal = [x for x in sys.stdin.readline().split()]
        features = set(animal[2:])

        print "%.7f" % traverse(node, features)

