// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。
// 对应每个测试案例，输出两个数，小的先输出。

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> res{sum - 1, sum - 1};  //保证初始化的两个值加起来不等于sum
        int product = INT_MAX;
        int lo = 0, hi = array.size() - 1;
        while (lo < hi) {
            int curSum = array[lo] + array[hi];
            if (curSum < sum) {
                ++lo;
            } else if (curSum > sum) {
                --hi;
            } else {
                if (array[lo] * array[hi] < product) {
                    product = array[lo] * array[hi];
                    res[0] = array[lo];
                    res[1] = array[hi];
                }
                ++lo;
                --hi;
            }
        }
        return res[0] + res[1] == sum ? res : vector<int>{};
    }
};