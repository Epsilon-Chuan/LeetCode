// 输入一棵二叉树，求该树的深度。
// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

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
    int TreeDepth(TreeNode *pRoot) {  // 中序遍历法
        if (pRoot == nullptr) return 0;
        stack<TreeNode *> buff;
        buff.push(pRoot);
        int res = 0, depth = 1;
        while (!buff.empty()) {
            auto cur = buff.top();
            buff.pop();
            if (cur->left == nullptr && cur->right == nullptr) {
                res = max(res, depth);
                --depth;
            } else {
                if (cur->left) buff.push(cur->left);
                if (cur->right) buff.push(cur->right);
                ++depth;
            }
        }
        return res;
    }
};