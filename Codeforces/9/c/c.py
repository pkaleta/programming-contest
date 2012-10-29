import sys

n = int(sys.stdin.readline())
m = ""

while n > 0:
    m = m+str(n%10)
    n /= 10

m = m[::-1]

s = ""
flag = False
for i in range(len(m)):
    if flag:
        s += "1"
    if not flag:
        if int(m[i]) not in [0, 1]:
            flag = True
            s += "1"
        else:
            s += m[i]
print int(s, 2)
