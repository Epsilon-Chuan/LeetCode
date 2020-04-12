// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;  // 呃...
        return helper(sequence.cbegin(), sequence.size());
    }
    bool helper(vector<int>::const_iterator begin, int length) {
        if (length <= 1) return true;  // 递归基
        auto root = begin + length - 1;
        // 寻找左右子树切分点
        int cutPoint = 0;
        while (cutPoint < length - 1)
            if (*(begin + cutPoint) > *root)
                break;
            else
                ++cutPoint;
        // 开始递归判断
        for (int i = cutPoint; i < length - 1; ++i)
            if (*(begin + i) < *root) return false;
        return helper(begin, cutPoint) &&
               helper(begin + cutPoint, length - 1 - cutPoint);
    }
};

int main() {
    vector<int> a{1, 2, 4, 6, 5, 3};
    Solution s;
    cout << boolalpha << s.VerifySquenceOfBST(a);
}