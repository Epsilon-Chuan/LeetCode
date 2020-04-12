// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
// 保证base和exponent不同时为0

class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1;
        int sign = exponent > 0 ? 1 : -1;
        if (sign < 0) exponent *= -1;
        for (int i = 0; i < exponent; ++i) res *= base;
        return sign > 0 ? res : 1 / res;
    }
};