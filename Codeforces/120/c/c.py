import sys

n = int(sys.stdin.readline())
type_str = sys.stdin.readline().split()

def construct(i):
    #    print type_str[i:]
    if i >= len(type_str):
        #        print '********'
        return None, True, -1

    if type_str[i] == "pair":
        left, error, p = construct(i+1)
        if error:
            return None, True, -1
        right, error, q = construct(p)
        if error:
            return None, True, -1
        #        print "1"
        return ((left, right), False, q)
    else:
        #        print "2"
        return ("int", False, i+1)

ret = ""

def tostr(node):
    #    print node
    if type(node) == str:
        return "int"
    else:
        return "pair<%s,%s>" % (tostr(node[0]), tostr(node[1]))

tree, error, i = construct(0)

if error:
    print "Error occurred"
else:
    print tostr(tree)
