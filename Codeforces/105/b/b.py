import sys

vp, vd, t, f, c = map(int, ' '.join(sys.stdin.readlines()).split())

p_dist = vp * t
d_dist = 0
eps = float(10) ** float(-6)

if p_dist >= c or vp >= vd:
    print 0
else:
    ret = 0
    while True:
        if float(p_dist) + float(eps) >= c:
            break
        t0 = float(p_dist) / float(vd-vp)
        p_dist += vp * t0
        if float(p_dist) + float(eps) >= c:
            break
        ret += 1
        t1 = float(p_dist) / float(vd)
        p_dist += vp * float(t1 + f)
    print ret
