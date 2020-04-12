// 大家都知道斐波那契数列，现在要求输入一个整数n，
// 请你输出斐波那契数列的第n项（从0开始，第0项为0），n <= 39

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0 || n == 1) return n;
        int prev1 = 1, prev2 = 0, res;
        for (int i = 2; i <= n; ++i) {
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};