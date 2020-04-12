// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) return false;  // pRoot2为空树时,根据题目判定为false
        if (same(pRoot1, pRoot2)) return true;
        if (!pRoot1)  // 此处判定和same内部的判定可能有重合,但无大碍
            return false;
        else
            return HasSubtree(pRoot1->left, pRoot2) ||
                   HasSubtree(pRoot1->right, pRoot2);
    }
    bool same(TreeNode* root1, TreeNode* root2) {
        if (!root2)  // 只要root2为空,总是返回true
            return true;
        else if (!root1)  // root2不为空,root1为空,返回false
            return false;
        // 此后root1和root2都不为空
        else if (root1->val != root2->val)  // root1和root2节点值不等,返回false
            return false;
        else  // root1和root2节点值都不为空且相等
            return same(root1->left, root2->left) &&
                   same(root1->right, root2->right);
    }
};