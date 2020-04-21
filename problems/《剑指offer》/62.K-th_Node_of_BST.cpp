// 给定一棵二叉搜索树，请找出其中的第k小的结点。
// 例如, (5,3,7,2,4,6,8), 按结点数值大小顺序第三小结点的值为4。

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == nullptr || k < 1) return nullptr;
        return helper(pRoot, k);
    }

    // 我靠，递归是个什么东西啊！！！
    TreeNode* helper(TreeNode* root, int& k) {
        TreeNode* target = nullptr;
        if (root->left) target = helper(root->left, k);
        if (target == nullptr) {
            if (k == 1) target = root;
            --k;
        }
        if (target == nullptr && root->right) target = helper(root->right, k);
        return target;
    }
};