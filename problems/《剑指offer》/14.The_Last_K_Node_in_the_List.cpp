// 输入一个链表，输出该链表中倒数第k个结点。

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        auto slow = pListHead, fast = pListHead;
        for (int i = 0; i < k; ++i)
            if (fast == nullptr)
                return nullptr;
            else
                fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};