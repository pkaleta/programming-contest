#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXLEN = 100;

class BigNumber {
    private:
        int length;
        bool sign;
        char digits[MAXLEN];

    public:
        BigNumber() : length(1), sign(true) {
            memset(digits, 0, sizeof(digits));
        }

        BigNumber(long long n) : length(0) {
            sign = n >= 0;
            n = abs(n);
            memset(digits, 0, sizeof(digits));
            while (n) {
                *(digits + (length++)) = n % 10;
                n /= 10;
            }
            length = max(1, length);
        }

        BigNumber operator + (const BigNumber& b) const {
            BigNumber result = BigNumber();
            if (this->sign == b.sign) {
                int l = max(this->length, b.length);
                for (int i = 0; i < l; ++i) {
                    result.digits[i] += this->digits[i] + b.digits[i];
                    if (result.digits[i] > 9) {
                        result.digits[i + 1] = 1;
                        result.digits[i] %= 10;
                    }
                }
                result.length = l;
                if (result.digits[l]) {
                    ++result.length;
                }
                result.sign = this->sign;
                return result;
            } else {
                if (!this->sign) {
                    BigNumber a = *this;
                    a.sign = true;
                    return b - a;
                } else {
                    BigNumber a = b;
                    a.sign = true;
                    return *this - a;
                }
            }
        }

//        BigNumber* operator - () {
//            BigNumber* result = this;
//            result->sign = !result->sign;
//            return result;
//        }

        BigNumber operator - (const BigNumber& b) const {
            BigNumber result = *this;
            if (!b.sign) {
                BigNumber a = b;
                a.sign = true;
                return *this + a;
            }
            if (!this->sign) {
                BigNumber a = *this;
                a.sign = true;
                BigNumber result = a + b;
                result.sign = false;
                return result;
            } else {
                if (*this < b) {
                    BigNumber a = *this;
                    BigNumber result = b - a;
                    result.sign = false;
                    return result;
                }
                for (int i = 0; i < b.length; ++i) {
                    result.digits[i] -= b.digits[i];
                    if (result.digits[i] < 0) {
                        result.digits[i] += 10;
                        --result.digits[i + 1];
                    }
                }
                return result;
            }
        }


        bool operator == (const BigNumber& b) const {
            if (this->sign != b.sign) {
                return false;
            }
            if (this->length != b.length) {
                return false;
            }
            for (int i = this->length - 1; i >= 0; --i) {
                if (this->digits[i] != b.digits[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator < (const BigNumber& b) const {
            if (this->sign == b.sign) {
                if (this->length > b.length) {
                    return false;
                }
                if (this->length < b.length) {
                    return true;
                }
                for (int i = this->length - 1; i >= 0; --i) {
                    if (this->digits[i] > b.digits[i]) {
                        return false;
                    }
                }
                return true;
            } else {
                return !this->sign;
            }
        }

        bool operator > (const BigNumber& b) const {
            if (this->sign == b.sign) {
                if (this->length < b.length) {
                    return false;
                }
                if (this->length > b.length) {
                    return true;
                }
                for (int i = this->length - 1; i >= 0; --i) {
                    if (this->digits[i] < b.digits[i]) {
                        return false;
                    }
                }
                return true;
            } else {
                return this->sign;
            }
        }

        bool operator <= (const BigNumber& b) const {
            return (*this < b || *this == b);
        }

        bool operator >= (const BigNumber& b) const {
            return (*this > b || *this == b);
        }

        BigNumber operator * (const BigNumber& b) const {
            BigNumber result = BigNumber();
            result.sign = !(this->sign ^ b.sign);
            for (int i = 0; i < this->length; ++i) {
                for (int j = 0; j < b.length; ++j) {
                    result.digits[j + i] += this->digits[i] * b.digits[j];
                    if (result.digits[j + i] > 9) {
                        result.digits[j + i + 1] += result.digits[j + i] / 10;
                        result.digits[j + i] %= 10;
                    }
                }
            }
            for (int i = 0; i < MAXLEN; ++i) {
                if (result.digits[i]) {
                    result.length = i + 1;
                }
            }
            return result;
        }

        void print() {
            if (!this->sign) {
                printf("-");
            }
            for (int i = this->length - 1; i >= 0; --i) {
                printf("%d", this->digits[i]);
            }
        }

        void println() {
            print();
            printf("\n");
        }

        int getLength() {
            return length;
        }
};

class Point {
    public:
        int x;
        int y;

        Point() {}

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

int ccw(Point p0, Point p1, Point p2)
{
    int dx1, dx2, dy1, dy2;

    dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

    if (dx1*dy2 > dy1*dx2)
        return 1;
    if (dx1*dy2 < dy1*dx2)
        return -1;
    if ((dx1*dx2 < 0) || (dy1*dy2 < 0))
        return -1;
    if ((dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2))
        return 1;
    return 0;
}

const int MAXK = 1005;

boolean crosses(Point a, Point b, Point c, Point d) {
    int a = ccw(a, b, c);
    int b = ccw(a, b, d);
    return ((a == 0 && b == 0) || (a * b < 0));
}

int main() {
    int d, k;
    Point s;
    Point ps[MAXK];
    Point p;

    scanf("%d", &d);
    while (d--) {
        scanf("%d%d", &s.x, &s.y);
        p.x = s.x;
        p.y = -1;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &ps[i].x, &ps[i].y);
            if (ps[i].y > p.y) {
                p.y = ps[i].y;
            }
        }
        ++p.y;
        printf("linia: (%d, %d), (%d, %d)\n", s.x, s.y, p.x, p.y);
        int cs = 0;
        for (int i = 1; i < k; ++i) {
            if (crosses(s, p, ps[i - 1], ps[i])) {
                ++cs;
            }
        }
        if (crosses(s, p, ps[k - 1], ps[0])) {
            ++cs;
        }

        if (cs & 1) {
            printf("TAK\n");
        } else {
            printf("NIE\n");
        }
    }
    return 0;
}


