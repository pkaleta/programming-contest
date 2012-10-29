
const int MAX_DIGITS = 1000;

class BigNumber {
    public:
        char digits[MAX_DIGITS];
        int size;
        int base;
        bool sign;

        BigNumber(int base=10) {
            this->sign = true;
            this->base = base;
            this->size = 0;
            memset(this->digits, 0, MAX_DIGITS);
        }

        BigNumber(const char* num, int base=10) {
            this->sign = true;
            this->base = base;
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
                    result->digits[i] = this->digits[i] - num.digits[i];
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

        BigNumber& operator / (BigNumber& num) {
            BigNumber* result = new BigNumber();
            char tmp[MAX_DIGITS];
            memset(tmp, 0, MAX_DIGITS);
            
        }

        void print() {
            for (int i = this->size - 1; i >= 0; --i) {
                printf("%d", this->digits[i]);
            }
            printf("\n");
        }
};
