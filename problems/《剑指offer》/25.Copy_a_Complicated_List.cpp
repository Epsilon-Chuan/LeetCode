// 输入一个复杂链表(每个节点中有节点值，以及两个指针，一个指向下一个节点，
// 另一个特殊指针指向任意一个节点)，返回结果为复制后复杂链表的head。
// 注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空。

#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        unordered_map<RandomListNode*, RandomListNode*> hash;
        auto fakeHead = new RandomListNode(0), prev = fakeHead;
        for (auto original = pHead; original; original = original->next) {
            auto node = new RandomListNode(original->label);
            prev->next = node;
            prev = prev->next;
            hash[original] = node;
        }
        for (auto original = pHead; original; original = original->next)
            hash[original]->random = hash[original->random];
        return fakeHead->next;
    }
};