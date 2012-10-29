#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 24;
const int MAXK = 24;
const int MAX_DIGITS = 25;

class BigNumber {
    public:
        char digits[MAX_DIGITS];
        int size;
        bool sign;

        BigNumber(long long num) {
            size = 0;
            sign = true;
            memset(digits, 0, MAX_DIGITS);
            while (num) {
                digits[size++] = num % 10;
                num /= 10;
            }
        }

        BigNumber() {
            this->sign = true;
            this->size = 0;
            memset(this->digits, 0, MAX_DIGITS);
        }

        BigNumber(const char* num) {
            this->sign = true;
            this->size = 0;
            memset(this->digits, 0, MAX_DIGITS);
            while (*num) {
                ++this->size;
                ++num;
            }
            --num;
            for (int i = 0; i < this->size; ++i) {
                this->digits[i] = (*num--) - '0';
            }
        }

        BigNumber& operator * (BigNumber& num) {
            BigNumber* result = new BigNumber();
            if ((this->size == 1 && *this->digits == 0) || (num.size == 1 && num.digits[0] == 0)) {
                result->size = 1;
                result->digits[0] = 0;
                return *result;
            }
            result->sign = !(this->sign ^ num.sign);
            for (int i = 0; i < this->size; ++i) {
                for (int j = 0; j < num.size; ++j) {
                    result->digits[i + j] += this->digits[i] * num.digits[j];
                    result->size = max(result->size, i + j);
                    if (result->digits[i + j] >= 10) {
                        result->size = max(result->size, i + j + 1);
                        result->digits[i + j + 1] += result->digits[i + j] / 10;
                        result->digits[i + j] %= 10;
                    }
                }
            }
            ++result->size;
            return *result;
        }

        BigNumber& operator / (BigNumber& num) {
            BigNumber* res = new BigNumber((long long) 0);
            BigNumber current = BigNumber((long long) 0);
            int offset = -1;
            for (int i = this->size - 1; i >= 0; --i) {
                current = current + *(new BigNumber(this->digits[i]));
                while (current >= num) {
                    if (offset == -1) {
                        offset = i;
                    }
                    current = current - num;
                    ++res->digits[i];
                }
                if (offset > -1) {
                    ++res->size;
                }
                current = current * *(new BigNumber(10));
            }
            if (res->size == 0) {
                res->size = 1;
                res->digits[0] = 0;
            }
            return *res;
        }

        BigNumber& operator % (BigNumber& num) {
            BigNumber& d = (*this / num) * num;
            return *this - d;
        }

        BigNumber& operator + (BigNumber& num) {
            BigNumber* result = new BigNumber();
            if (this->sign == num.sign) {
                result->sign = this->sign;
            } else {
                if (this->sign == false) {
                    this->sign = true;
                    return num - *this;
                } else {
                    num.sign = true;
                    return *this - num;
                }
            }
            result->size = max(this->size, num.size);
            for (int i = 0; i < result->size; ++i) {
                result->digits[i] += this->digits[i] + num.digits[i];
                if (result->digits[i] >= 10) {
                    result->digits[i + 1] += result->digits[i] / 10;
                    result->digits[i] %= 10;
                }
            }
            if (result->digits[result->size])
                ++result->size;
            return *result;
        }

        BigNumber& operator - (BigNumber& num) {
            BigNumber* result;
            if (*this < num) {
                result = &(num - *this);
                result->sign = false;
            } else {
                result = new BigNumber();
                result->size = 0;
                for (int i = 0; i < this->size; ++i) {
                    result->digits[i] += this->digits[i] - num.digits[i];
                    if (result->digits[i] < 0) {
                        result->digits[i] += 10;
                        --result->digits[i + 1];
                    }
                    if (result->digits[i] > 0)
                        result->size = max(result->size, i);
                }
                ++result->size;
            }
            return *result;
        }

        bool operator < (BigNumber& num) {
            if (this->size < num.size)
                return true;
            if (this->size > num.size)
                return false;
            int i = this->size;
            while (i >= 0 && this->digits[i] == num.digits[i])
                --i;
            if (i < 0)
                return false;
            return this->digits[i] < num.digits[i];
        }

        bool operator > (BigNumber& num) {
            if (this->size > num.size)
                return true;
            if (this->size < num.size)
                return false;
            int i = this->size;
            while (i >= 0 && this->digits[i] == num.digits[i])
                --i;
            if (i < 0)
                return false;
            return this->digits[i] > num.digits[i];
        }

        bool operator == (BigNumber& num) {
            if (this->size != num.size)
                return false;
            for (int i = 0; i < this->size; ++i) {
                if (this->digits[i] != num.digits[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator >= (BigNumber& num) {
            return *this > num || *this == num;
        }

        bool operator <= (BigNumber& num) {
            return *this < num || *this == num;
        }

        void print() {
            if (!this->sign && (this->size > 1 || this->digits[0] != 0)) {
                printf("-");
            }
            for (int i = this->size - 1; i >= 0; --i)
                printf("%d", this->digits[i]);
        }
};

BigNumber& operator / (BigNumber& a, int b) {
    BigNumber* bb = new BigNumber(b);
    return a / (*bb);
}

BigNumber& operator * (int a, BigNumber& b) {
    BigNumber* aa = new BigNumber(a);
    return b * (*aa);
}

BigNumber& operator * (BigNumber& b, int a) {
    BigNumber* aa = new BigNumber(a);
    return b * (*aa);
}

BigNumber& operator + (int a, BigNumber& b) {
    BigNumber* aa = new BigNumber(a);
    return (*aa) + b;
}

BigNumber& operator + (BigNumber& b, int a) {
    BigNumber* aa = new BigNumber(a);
    return (*aa) + b;
}

BigNumber& operator - (int a, BigNumber& b) {
    BigNumber* aa = new BigNumber(a);
    return (*aa) - b;
}

BigNumber& operator - (BigNumber& b, int a) {
    BigNumber* aa = new BigNumber(a);
    return b - (*aa);
}

BigNumber& operator % (BigNumber& b, int a) {
    BigNumber* aa = new BigNumber(a);
    return b % (*aa);
}

BigNumber& operator ^ (BigNumber a, int b) {
    BigNumber* res = new BigNumber(1);
    if (b == 0) {
        return *res;
    }
    while (b) {
        if (b % 2) {
            res = &(*res * a);
        }
        a = a * a;
        b /= 2;
    }
    if (!a.sign && b & 1) {
        res->sign = false;
    }
    return *res;
}

BigNumber nk[MAXN + 1][MAXK + 1];

void prepare() {
    for (int n = 0; n <= MAXN; ++n) {
        for (int k = 0; k <= MAXN; ++k) {
            nk[n][k] = BigNumber((long long)0);
        }
    }
    nk[0][0] = *(new BigNumber(1));
    for (int n = 1; n <= MAXN; ++n) {
        nk[n][0] = BigNumber(1);
        for (int k = 1; k <= n; ++k) {
            nk[n][k] = nk[n - 1][k - 1] + nk[n - 1][k];
        }
    }
}

int main() {
    int d, n, k;
    scanf("%d", &d);
    prepare();

    while (d--) {
        scanf("%d%d", &k, &n);
        BigNumber res = BigNumber((long long) 0);
        BigNumber minusOne = BigNumber(1);
        minusOne.sign = false;
        for (int d = 0; d < k; ++d) {
            BigNumber tmp = BigNumber(k - d);
            res = res + ((minusOne ^ d) * nk[k][d] * (tmp ^ n));
        }
        BigNumber s = res % 60; res = res / 60;
        BigNumber m = res % 60; res = res / 60;
        BigNumber h = res % 24; res = res / 24;
        res.print();
        printf(":");
        h.print();
        printf(":");
        m.print();
        printf(":");
        s.print();
        printf("\n");
    }

    return 0;
}
