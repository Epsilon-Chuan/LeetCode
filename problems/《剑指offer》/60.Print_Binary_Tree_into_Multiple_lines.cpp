// 从上到下按层打印二叉树，同一层结点从左至右输出。
// 每一层输出一行。

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
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr) return res;
        queue<TreeNode *> buffer;
        buffer.push(pRoot);
        while (!buffer.empty()) {
            vector<int> oneTraverse;
            queue<TreeNode *> nextLayer;
            while (!buffer.empty()) {
                auto cur = buffer.front();
                oneTraverse.push_back(cur->val);
                if (cur->left) nextLayer.push(cur->left);
                if (cur->right) nextLayer.push(cur->right);
                buffer.pop();
            }
            res.push_back(oneTraverse);
            swap(buffer, nextLayer);
        }
        return res;
    }
};