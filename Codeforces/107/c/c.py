import sys

q = int(sys.stdin.readline())
dp = {}

i = 2
divs = []
while i * i <= q:
    if q % i == 0:
        divs.append(i)
        divs.append(q/i)
    i += 1
divs = sorted(divs)
print divs

def solve(n):
    if n in dp:
        return dp[n]
    prime = True
    i = 0
    while i < len(divs) and n > divs[i]:
        d = divs[i]
        if n % d == 0:
            prime = False
            winning, move = solve(d)
            if not winning:
                dp[n] = (True, d)
                return (True, d)
        i += 1
    dp[n] = (prime, 0)
    return (prime, 0)

for d in divs:
    solve(d)
solve(q)

winning, move = dp[q]
if winning:
    print "1", move
else:
    print "2"
