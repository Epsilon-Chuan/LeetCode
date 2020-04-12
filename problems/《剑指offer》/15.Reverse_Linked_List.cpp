// 输入一个链表，反转链表后，输出新链表的表头。

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *cur = pHead, *pre = nullptr, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};