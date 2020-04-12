// 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
// 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
// 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
// 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
// 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        // 应该再尝试双指针法
        vector<vector<int>> res;
        for (int start = 1; start < sum; ++start) {
            vector<int> curSeq;
            for (int size = 1; size < sum; ++size) {
                curSeq.push_back(start + size - 1);
                int curSum = (2 * start + size - 1) * size / 2;  // 高斯公式
                if (curSum == sum) {
                    res.push_back(curSeq);
                    break;
                } else if (curSum > sum)
                    break;
            }
        }
        return res;
    }
};