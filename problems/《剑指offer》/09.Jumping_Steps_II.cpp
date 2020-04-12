// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0) return 0;
        int res = 1;
        for (int i = 1; i < number; ++i) res *= 2;
        return res;
    }
};