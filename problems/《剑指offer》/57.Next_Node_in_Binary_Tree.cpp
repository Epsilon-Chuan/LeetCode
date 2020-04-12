// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;  // parent
    TreeLinkNode(int x)
        : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode->left == nullptr && pNode->right == nullptr) {
            if (pNode->next && pNode->next->left == pNode) return pNode->next;
            if (pNode->next && pNode->next->right == pNode)
                return findUp(pNode->next);
            return nullptr;
        } else {
            if (pNode->right) return findDown(pNode->right);
            if (pNode->next) return pNode->next;
            return nullptr;
        }
    }

    TreeLinkNode *findDown(TreeLinkNode *root) {
        if (root->left)
            return findDown(root->left);
        else
            return root;
    }

    TreeLinkNode *findUp(TreeLinkNode *rChild) {
        if (rChild->next == nullptr) return nullptr;
        if (rChild->next->right == rChild)
            return findUp(rChild->next);
        else
            return rChild->next;
    }
};