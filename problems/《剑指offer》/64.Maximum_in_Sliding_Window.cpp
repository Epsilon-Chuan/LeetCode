// 给定一个数组和滑动窗口的大小,找出所有滑动窗口里数值的最大值.
// 例如,如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3,
// 那么一共存在6个滑动窗口,他们的最大值分别为{4,4,6,6,6,5};
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个:
// {[2,3,4],2,6,2,5,1}, {2,[3,4,2],6,2,5,1}, {2,3,[4,2,6],2,5,1},
// {2,3,4,[2,6,2],5,1}, {2,3,4,2,[6,2,5],1}, {2,3,4,2,6,[2,5,1]}.

#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        deque<int> window;
        vector<int> res;
        for (int i = 0; i < num.size(); ++i) {
            while (!window.empty() && num[i] > num[window.back()])
                window.pop_back();
            window.push_back(i);
            if (i - window.front() > size - 1) window.pop_front();
            if (i >= size - 1) res.push_back(num[window.front()]);
        }
        return res;
    }
};