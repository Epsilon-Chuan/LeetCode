// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
// 比如n=3时，2*3的矩形块有3种覆盖方法：

class Solution {
public:
    int rectCover(int number) {
        if (number == 1 || number == 2) return number;
        int res, prev1 = 2, prev2 = 1;
        for (int i = 3; i <= number; ++i) {
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};