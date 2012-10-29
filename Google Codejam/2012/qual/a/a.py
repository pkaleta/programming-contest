import sys

GOOGLERESE = ["q",
              "a zoo",
              "ejp mysljylc kd kxveddknmc re jsicpdrysi"
              "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
              "de kr kd eoya kw aej tysr re ujdr lkgc jv"]

TRANSLATION = ["z",
               "y qee",
               "our language is impossible to understand"
               "there are twenty six factorial possibilities"
               "so it is okay if you want to just give up"]

def find_mapping():
    mapping = {}
    corpus = zip(GOOGLERESE, TRANSLATION)
    for googlerese, translation in corpus:
        new_mapping = zip(googlerese, translation)
        mapping.update(dict(new_mapping))
    return mapping

def translate(mapping, sentence):
    return ''.join([mapping[c] for c in sentence])

if __name__ == "__main__":
    mapping = find_mapping()
    n = int(sys.stdin.readline())
    for i in xrange(n):
        sentence = sys.stdin.readline().strip()
        print "Case #%d: %s" % (i + 1, translate(mapping, sentence))

