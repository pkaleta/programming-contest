import sys

n = int(sys.stdin.readline())
p = map(int, sys.stdin.readline().split())
p = sorted(p)

# i = 1
# ret = [1]
# while i < n:
#     if p[i] != p[i-1]:
#         ret.append(p[i-1])
#     else:
#         ret.append(p[i])
#     i += 1

# print ' '.join(map(str, ret))

x = p[len(p)-1]
if x == 1:
    print ' '.join(map(str, p[:-1] + [2]))
else:
    print ' '.join(map(str, [1] + p[:-1]))
