#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
const int MAX_DIGITS = 500;

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

        BigNumber& operator + (BigNumber& num) {
            BigNumber* result = new BigNumber();
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

        void print() {
            for (int i = this->size - 1; i >= 0; --i)
                printf("%d", this->digits[i]);
        }
};

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

BigNumber* t[MAX_N];

void initialize() {
    t[3] = new BigNumber("16");
    t[4] = new BigNumber("45");
    for (int i = 5; i < MAX_N; ++i)
        t[i] = &(3 * *t[i - 1] - *t[i - 2] + 2);
}

int main() {
    int c, n;

    initialize();
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        t[n]->print();
        printf("\n");
    }
    return 0;
}
