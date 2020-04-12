// 在一个排序的链表中,存在重复的结点,请删除该链表中重复的结点
// 重复的结点不保留,返回链表头指针。
// 例如,链表 1->2->3->3->4->4->5 处理后为 1->2->5

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        auto pseudoHead = new ListNode(0);
        pseudoHead->next = pHead;
        auto left = pseudoHead, right = pHead;
        while (right && right->next) {
            if (right->val == right->next->val) {
                while (right->next && right->val == right->next->val)
                    right = right->next;
                right = right->next;
            } else {
                left->next = right;
                left = left->next;
                right = right->next;
            }
        }
        left->next = right;
        auto res = pseudoHead->next;
        delete pseudoHead;
        return res;
    }
};