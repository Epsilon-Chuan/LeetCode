// 输入两个链表，找出它们的第一个公共结点。
// 注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        auto left = pHead1, right = pHead2;
        int sign = 0;
        while (left && right) {
            if (left == right)
                return left;
            else {
                left = left->next;
                right = right->next;
            }
            if (left == nullptr && sign < 2) {
                left = pHead2;
                ++sign;
            }
            if (right == nullptr && sign < 2) {
                right = pHead1;
                ++sign;
            }
        }
        return nullptr;
    }
};