import sys
import random

max_word_len = 20
max_words = 100
max_tests = 20
max_w = 1000
max_h = 1000

def random_word(length):
    w = []
    for i in xrange(length):
        w.append(chr(random.randint(ord('a'), ord('z'))))
    return ''.join(w)

T = random.randint(1, max_tests)
print T
for t in xrange(T):
    s = []
    for w in xrange(max_words):
        s.append(random_word(random.randint(1, max_word_len)))
    w = random.randint(1, max_w)
    h = random.randint(1, max_h)
    print "%d %d %s" % (w, h, ' '.join(s))
