// 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        auto cur = head;
        stack<int> records;
        while (cur) {
            records.push(cur->val);
            cur = cur->next;
        }
        vector<int> res(records.size());
        for (int i = 0; i < res.size(); ++i) {
            res[i] = records.top();
            records.pop();
        }
        return res;
    }
};