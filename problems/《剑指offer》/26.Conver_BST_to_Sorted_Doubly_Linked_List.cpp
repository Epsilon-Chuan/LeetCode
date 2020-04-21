// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        helper(pRootOfTree, pre);
        TreeNode* res = pRootOfTree;
        while (res->left) res = res->left;
        return res;
    }
    void helper(TreeNode* cur, TreeNode*& pre) {  // 中序遍历
        if (cur == nullptr) return;

        helper(cur->left, pre);

        cur->left = pre;
        if (pre) pre->right = cur;
        pre = cur;

        helper(cur->right, pre);
    }
};
