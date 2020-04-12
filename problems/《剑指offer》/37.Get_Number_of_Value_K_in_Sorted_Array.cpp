// 统计一个数字在排序数组中出现的次数。

#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty()) return 0;
        int iL, iR;
        int lo = 0, hi = data.size() - 1;  // 能否用左闭右开区间实现？
        while (lo < hi) {                  // 找最小秩
            int mi = (lo + hi) / 2;
            (k > data[mi]) ? lo = mi + 1 : hi = mi;
        }
        if (data[lo] != k) return 0;
        iL = lo;

        lo = 0, hi = data.size() - 1;
        while (lo < hi) {                // 找最大秩
            int mi = (lo + hi) / 2 + 1;  // Make it biased to the right
            (k < data[mi]) ? hi = mi - 1 : lo = mi;
        }
        iR = hi;
        return iR - iL + 1;
    }
};