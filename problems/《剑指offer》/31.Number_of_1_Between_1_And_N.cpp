// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数
// (从1到 n 中1出现的次数)

// 还是暴力法简单直接...
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int times = 0;
        for (int i = 1; i <= n; ++i) {
            int i_copy = i, i_times = 0;
            while (i_copy > 0) {
                if (i_copy % 10 == 1) ++i_times;
                i_copy /= 10;
            }
            times += i_times;
        }
        return times;
    }
};