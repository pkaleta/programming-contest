n = input()
S = map(int,raw_input().split())
amin = max([float(S[i]  )/(i+1) for i in range(n)])
amax = min([float(S[i]+1)/(i+1) for i in range(n)])
print "************", amin, amax
smin = int(amin*(n+1)+1e-9)
smax = int(amax*(n+1)-1e-9)
if smin==smax:
    print "unique"
    print smin
else:
    print "not unique"


