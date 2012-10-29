#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAX_N = 1001;
const int MAX_DIGITS = 301;

class BigNumber {
    public:
        char digits[MAX_DIGITS];
        int size;

        BigNumber() {
            this->size = 0;
            memset(this->digits, 0, MAX_DIGITS);
        }

        BigNumber(const char* num) {
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

        BigNumber& operator*(BigNumber& num) {
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

        BigNumber& operator+(BigNumber& num) {
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

        void print() {
            for (int i = this->size - 1; i >= 0; --i) {
                printf("%d", this->digits[i]);
            }
            printf("\n");
        }
};

BigNumber* t[MAX_N];

void initialize() {
    t[0] = new BigNumber("1");
    BigNumber* two = new BigNumber("2");
    for (int i = 1; i < MAX_N; ++i)
        t[i] = &((*t[i - 1]) * (*two));
}

int main() {
    int n, left;

    initialize();

    scanf("%d", &n);
    --n;
    BigNumber* result = new BigNumber();
    left = 1;
    if (n == -1)
        printf("0");
    while (n > -1) {
        result = &((*result) + (*t[n]));
        if (--left && --n > -1) {
            result = &((*result) + (*t[n]));
            left = 2;
        } else {
            left = 2;
        }
        n -= 2;
    }
    result->print();
    return 0;
}
