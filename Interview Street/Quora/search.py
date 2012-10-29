import sys
from collections import defaultdict

n = int(sys.stdin.readline())
objects = defaultdict(set)

deleted = set([])
ord_num = {}

def compare((s1, n1, x, y), (s2, n2, a, b)):
    if s1 > s2:
        return -1
    elif s1 < s2:
        return 1
    elif s1 == s2:
        if n1 > n2:
            return -1
        else:
            return 1

def prefixes(word):
    for i in xrange(1, len(word)+1):
        yield word[:i]

def add(type, id, score, words, num):
    global deleted
    ord_num[id] = num
    deleted.discard(id)
    for word in words:
        for prefix in prefixes(word):
            objects[prefix].add((score, num, type, id))

def delete(id):
    global deleted
    deleted.add((id, ord_num[id]))

def query(nresults, words, return_all=False):
    global deleted
    results = objects[words[0]]
    for word in words[1:]:
        current_results = objects[word]
        results = results.intersection(current_results)

    results = set(filter(lambda (score, num, tp, id): not (id, num) in deleted, results))
    if return_all:
        return results
    else:
        return sorted(results, cmp=compare)[:nresults]

def wquery(nresults, boosts, words):
    results = []
    for res in query(nresults, words, True):
        boosts_matched = []
        score, num, tp2, id = res
        for (tp, boost) in boosts:
            if tp == tp2:
                boosts_matched.append(boost)
            if tp == id:
                boosts_matched.append(boost)
        for b in boosts_matched:
            score *= b
        results.append((score, num, tp2, id))
    return sorted(results, cmp=compare)[:nresults]

def to_lower(words):
    return map(lambda word: word.lower(), words)

def print_results(results):
#    print "***", results
    print ' '.join(map(lambda (score, num, tp, id): id, results))

for i in xrange(n):
    command = sys.stdin.readline().strip().split()
    if command[0] == "ADD":
#        print "****", to_lower(command[4:])
        add(command[1], command[2], float(command[3]), to_lower(command[4:]), i)
    elif command[0] == "DEL":
        delete(command[1])
    elif command[0] == "QUERY":
        print_results(query(int(command[1]), to_lower(command[2:])))
    elif command[0] == "WQUERY":
        nboosts = int(command[2])
        def parse_boost(s):
            a, b = s.split(':')
            return (a, float(b))
        boosts = map(parse_boost, command[3:nboosts+3])
#        print "***", boosts
#        print "***", to_lower(command[nboosts+3:])
        print_results(wquery(int(command[1]), boosts, to_lower(command[nboosts+3:])))

