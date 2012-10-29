import sys

lines = []
checked = [False for i in range(40000)]
P1 = None
P2 = None
P3 = None
P4 = None
Q1 = None
Q2 = None
Q3 = None
Q4 = None


def check():
    for i in range(4):
        a = False
        b = False
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        p1 = [x1, y1]
        p2 = [x2, y2]

        if p1[1] == p2[1]:
            if p1[0] > p2[0]:
                tmp = p1[0]
                p1[0] = p2[0];
                p2[0] = tmp
            a = True
        if p1[0] == p2[0]:
            if p1[1] > p2[1]:
                tmp = p1[1]
                p1[1] = p2[1]
                p2[1] = tmp
            b = True
        if (a and b) or ((not a) and (not b)):
            return False
        lines.append([p1, p2])

    for i in range(len(lines)):
        if not checked[i]:
            p1, p2 = lines[i]
            if p1[1] == p2[1] and p1[0] < p2[0]:
                found = False
                for j in range(len(lines)):
                    if j != i and not checked[j]:
                        p3, p4 = lines[j]
                        if p3[1] == p4[1] and p3[1] != p1[1] and p3[0] == p1[0] and p4[0] == p2[0]:
                            found = True
                            checked[i] = True
                            checked[j] = True
                            break
                if not found:
                    return False
                if (p1[1] < p3[1]):
                    P1 = p1
                    P2 = p2
                    P3 = p3
                    P4 = p4
                else:
                    P1 = p3
                    P2 = p4
                    P3 = p1
                    P4 = p2

            elif p1[0] == p2[0] and p1[1] < p2[1]:
                found = False
                for j in range(len(lines)):
                    if j != i and not checked[j]:
                        p3, p4 = lines[j]
                        if p3[0] == p4[0] and p3[0] != p1[0] and p3[1] == p1[1] and p4[1] == p2[1]:
                            found = True
                            checked[i] = True
                            checked[j] = True
                            break
                if not found:
                    return False
                if (p1[0] < p3[0]):
                    Q1 = p1
                    Q2 = p2
                    Q3 = p3
                    Q4 = p4
                else:
                    Q1 = p3
                    Q2 = p4
                    Q3 = p1
                    Q4 = p2
            else:
                return False

    if P1 == Q1 and P2 == Q3 and P3 == Q2 and P4 == Q4:
        return True
    else:
        return False

if check():
    print "YES"
else:
    print "NO"
