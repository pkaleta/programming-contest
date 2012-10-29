#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_N = 105;
const int MAX_K = 105;
const int MAX_DIGITS = 35;

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

        BigNumber(int num) {
            memset(this->digits, 0, MAX_DIGITS);
            while (num) {
                this->digits[this->size++] = num % 10;
                num /= 10;
            }
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
            result = new BigNumber();
            memset(result, 0, MAX_DIGITS);
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

        bool operator < (int num) {
            return *this < *(new BigNumber(num));
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

        bool operator > (int num) {
            return *this > *(new BigNumber(num));
        }

        void print() {
            for (int i = this->size - 1; i >= 0; --i)
                printf("%d", this->digits[i]);
        }
};

bool operator > (int a, BigNumber& b) {
    return *(new BigNumber(a)) > b;
}

BigNumber* t[MAX_N][MAX_K];

void initialize() {
    for (int k = 0; k < MAX_K; ++k)
        for (int n = 0; n < MAX_N; ++n)
            t[n][k] = new BigNumber("0");
    for (int n = 0; n < MAX_N; ++n)
        t[n][0] = new BigNumber("1");
    for (int k = 1; k < MAX_K; ++k)
        for (int n = k; n < MAX_N; ++n)
            t[n][k] = &((*t[n - 1][k - 1]) + (*t[n - 1][k]));
//    for (int k = 1; k < MAX_K; ++k) {
//        for (int n = 1; n < MAX_N; ++n) {
//            t[n][k]->print();
//            printf(" ");
//        }
//        printf("\n");
//    }
}

int main() {
    int c, n, k;
    int nn, kk, dd;
    char result[MAX_N];
    int size;

    initialize();
    scanf("%d", &c);
    while (c--) {
        memset(result, 0, MAX_N);
        size = 0;
        scanf("%d %d", &nn, &kk);
        n = nn;
        k = kk;
        scanf("%d", &dd);

        BigNumber* d = new BigNumber(dd);
        BigNumber* one = new BigNumber("1");
        d = &((*t[n][k]) - (*d) + *one);
        while (n > 0 || k > 0) {
            if ((*d) > (*t[n - 1][k])) {
                result[size++] = '1';
                d = &((*d) - (*t[n - 1][k]));
                --n;
                --k;
            } else {
                result[size++] = '0';
                --n;
            }
        }
        for (int i = 0; i < size; ++i)
            printf("%c", result[i]);
        printf("\n");
    }
    return 0;
}
