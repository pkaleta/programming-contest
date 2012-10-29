import sys

n = int(sys.stdin.readline())
for t in range(n):
    alien_number, src_lng, dest_lng = sys.stdin.readline().split()
    src_base = len(src_lng)
    dest_base = len(dest_lng)
    tmp = 0
    for i, d in enumerate(alien_number[::-1]):
        tmp += src_lng.index(d) * src_base ** i
    result = ''
    while tmp:
        result += dest_lng[tmp % dest_base]
        tmp /= dest_base
    print "Case #%d: %s" % (t + 1, result[::-1])
