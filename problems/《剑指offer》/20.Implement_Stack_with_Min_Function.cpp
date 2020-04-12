// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数(时间复杂度应为O(1))。
// 注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

#include <algorithm>
#include <stack>
using namespace std;

class Solution {
    stack<int> _S, _minS;

public:
    void push(int value) {
        _S.push(value);
        if (_minS.empty())
            _minS.push(value);
        else
            _minS.push(::min(value, _minS.top()));
    }
    void pop() {
        _S.pop();
        _minS.pop();
    }
    int top() { return _S.top(); }
    int min() { return _minS.top(); }
};