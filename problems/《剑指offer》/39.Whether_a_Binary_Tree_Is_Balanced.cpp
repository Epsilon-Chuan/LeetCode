// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。

#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode *pRoot) {
        if (pRoot == nullptr) return true;

        int l = depth(pRoot->left), r = depth(pRoot->right);
        if (abs(l - r) > 1)
            return false;
        else
            return IsBalanced_Solution(pRoot->left) &&
                   IsBalanced_Solution(pRoot->right);
    }
    int depth(TreeNode *root) {
        if (root == nullptr) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};