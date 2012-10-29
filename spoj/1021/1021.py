def reconstruct_palindrome(n, s1, m, s2, dp):
    palindrome = []
    i = m - 1
    j = n - 1

    while True:
        if i == 0:
            palindrome.append(s1[1:j + 1][::-1])
            return "".join(palindrome)

        elif j == 0:
            palindrome.append(s2[1:i + 1][::-1])
            return "".join(palindrome)

        if s1[j] == s2[i]:
            palindrome.append(s1[j])
            i -= 1
            j -= 1
        else:
            if dp[i][j - 1] >= dp[i - 1][j]:
                palindrome.append(s1[j])
                j -= 1
            else:
                palindrome.append(s2[i])
                i -= 1


def lcs(s1, s2):
    s1 = " " + s1
    s2 = " " + s2
    n = len(s1)
    m = len(s2)

    dp = [[0 for j in xrange(n)]
          for i in xrange(m)]

    for i in xrange(1, m):
        for j in xrange(1, n):
            if s1[j] == s2[i]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

    return reconstruct_palindrome(n, s1, m, s2, dp)


def solve(s):
    return lcs(s, s[::-1])

if __name__ == "__main__":
    T = int(raw_input())
    for t in xrange(T):
        s = raw_input().strip()
        print solve(s)
