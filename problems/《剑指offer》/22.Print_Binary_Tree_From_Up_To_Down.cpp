// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        queue<TreeNode *> buffer;
        buffer.push(root);
        vector<int> res;
        while (!buffer.empty()) {
            auto cur = buffer.front();
            buffer.pop();
            if (cur) {
                res.push_back(cur->val);
                buffer.push(cur->left);
                buffer.push(cur->right);
            }
        }
        return res;
    }
};