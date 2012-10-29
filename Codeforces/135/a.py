import sys
from collections import defaultdict

count = defaultdict(int)

n = int(sys.stdin.readline())
s = sys.stdin.readline().strip()

for c in s:
    count[c] += 1


def get_string():
    l = len(s)

    result = ""
    for c, cnt in count.items():
        if cnt % n == 0:
            result += c * (cnt / n)
        else:
            return None
    return result * n
    # for d in xrange(1, l + 1):
    #     if l % d == 0:
    #         result = ""
    #         correct = True
    #         for c, cnt in count.items():
    #             if cnt % d == 0:
    #                 result += c * (cnt / d)
    #             else:
    #                 correct = False
    #                 break
    #         if correct and len(result) == n:
    #             return result * (l / n)

    # return None


result = get_string()
if result:
    print result
else:
    print "-1"
