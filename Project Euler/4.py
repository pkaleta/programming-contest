def is_palindrome(n):
    str_n = str(n)
    for i in range(len(str_n)):
        if str_n[i] != str_n[len(str_n)-i-1]:
            return False
        i -= 1
    return True

max_palindrome = 0
for a in range(100, 1000):
    for b in range(100, 1000):
        tmp = a * b
        if is_palindrome(tmp):
            print a, b, a*b
        if is_palindrome(tmp) and tmp > max_palindrome:
            max_palindrome = tmp
print max_palindrome, is_palindrome(90*91)
