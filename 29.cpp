#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        #define MAX_INT 2147483647
        int flag = 0;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            flag = 1;
        }
        long long dividend_ = dividend;
        dividend_ = dividend_ < 0 ? -dividend_ : dividend_;
        long long divisor_ = divisor;
        divisor_ = divisor_ < 0 ? -divisor_ : divisor_;
        if (divisor_ == 0)
            return MAX_INT;
        long long res = 0;
        while (dividend_ >= divisor_) {
            long long a = divisor_;
            long long m = 1;
            while ((a << 1) < dividend_) {
                a <<= 1;
                m <<= 1;
            }
            dividend_ -= a;
            res += m;
        }
        if (flag == 1)
            res = -res;
        if (res > MAX_INT)
            return MAX_INT;
        else 
            return res;
    }
};

int main () {
    Solution s;
    s.divide(-2147483648 , -1);
}