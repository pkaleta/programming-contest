import sys

n, o, w = map(int, sys.stdin.readline().split())

MAX = 50000

dp = {(0, 0, 0) : (1, 1, 1, None)}

def solve(n, o, w):
#    print n, o, w
    if (n, o, w) in dp:
        return dp[(n, o, w)]
    if n < 0:
        return None
    if n == 0:
        return None

    dp[(n, o, w)] = None
    x = float('inf')
    if o > 0:
        ret = solve(n-1, o-1, w)
        if ret != None:
            num, mx, suma, prev = solve(n-1, o-1, w)
            if mx+1 < x and mx+1 <= suma:
                x = mx+1
                dp[(n, o, w)] = (mx+1, mx+1, suma+mx+1, (n-1, o-1, w))
    if w > 0:
        ret = solve(n-1, o, w-1)
        if ret != None:
            num, mx, suma, prev = ret
            if suma+1 < x:
                x = suma+1
                dp[(n, o, w)] = (suma+1, max(mx, suma+1), suma+suma+1, (n-1, o, w-1))
    ret = solve(n-1, o, w)
    if ret != None:
        num, mx, suma, prev = ret
        if 1 < x:
            x = 1
            dp[(n, o, w)] = (1, max(1, mx), suma+1, (n-1, o, w))
    return dp[(n, o, w)]

solve(n, o, w)


ret = dp[(n-1, o, w)]
if ret is None:
    print -1
else:
    seq = []
    cur = (n-1, o, w)
    while cur != None:
        num, _, _, cur = dp[cur]
        seq.append(num)
    flag = False
    for x in seq:
        if x > MAX:
            flag = True
            break
    if flag:
        print -1
    else:
        print ' '.join(map(str, seq)[::-1])
