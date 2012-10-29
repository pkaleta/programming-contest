import sys
import re

words = []

l, d, n = [int(x) for x in sys.stdin.readline().split()]

for i in range(0, d):
    words.append(sys.stdin.readline().strip())

for i in range(0, n):
    tmp = sys.stdin.readline().strip()
    p = tmp.replace("(", "[").replace(")", "]")
    pattern = re.compile(p)
    result = 0
    for j in range(0, len(words)):
        if pattern.match(words[j]) != None:
            result += 1
    print "Case #%d: %d" %(i + 1, result)


