l = {1 : len('one'), 2 : len('two'), 3 : len('three'), 4 : len('four'), 5 : len('five'), 6 : len('six'), 7 : len('seven'), 8 : len('eight'), 9 : len('nine'), 10 : len('ten'), 11 : len('eleven'), 12 : len('twelve'),13 : len('thirteen'), 14 : len('fourteen'), 15 : len('fifteen'), 16 : len('sixteen'), 17 : len('seventeen'), 18 : len('eighteen'), 19 : len('nineteen'), 20 : len('twenty')}
l[1000] = len('onethousand')
l[30] = len('thirty')
l[40] = len('forty')
l[50] = len('fifty')
l[60] = len('sixty')
l[70] = len('seventy')
l[80] = len('eighty')
l[90] = len('ninety')
l[100] = ''

total = 0
for i in range(1, 1001):
    print 'liczba: ', i
    try:
        total += l[i]
        print 'z hasza: ', l[i]
    except KeyError:
        n = i
        if n % 100 / 10 == 1:
            total += l[n % 100]
            print l[n % 100]
            n /= 10
        else:
            if n % 10 != 0:
                print l[n % 10]
                total += l[n % 10]
            n /= 10
            total += l[(n % 10) * 10]
        n /= 10
        if n > 0:
            print l[n] + 10
            total += l[n] + len('hundredand')

print total
