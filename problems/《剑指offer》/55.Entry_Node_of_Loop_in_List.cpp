// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        auto slow = pHead, fast = pHead;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast && slow) break;
        }
        if (fast->next == nullptr) return nullptr;
        int number = 1;  // number of nodes in the ring
        for (auto cur = slow->next; cur != slow; cur = cur->next) ++number;
        slow = fast = pHead;
        for (int i = 0; i < number; ++i) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};