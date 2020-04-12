// 请实现一个函数，用来判断一颗二叉树是不是对称的。
// 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        if (pRoot == nullptr) return true;
        return helper(pRoot->left, pRoot->right);
    }
    bool helper(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if ((left == nullptr && right) || (right == nullptr && left))
            return false;
        else if (left->val != right->val)
            return false;
        else
            return helper(left->left, right->right) &&
                   helper(left->right, right->left);
    }
};