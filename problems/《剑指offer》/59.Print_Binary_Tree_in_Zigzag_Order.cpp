// 请实现一个函数按照之字形打印二叉树。
// 即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
// 第三行再按照从左到右的顺序打印，其他行以此类推。

#include <algorithm>
#include <deque>
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
        deque<TreeNode *> buffer{pRoot};
        bool leftToRight = true;
        while (!buffer.empty()) {
            deque<TreeNode *> nextLayer;
            vector<int> tmp;
            if (leftToRight) {
                while (!buffer.empty()) {
                    auto cur = buffer.front();
                    buffer.pop_front();
                    tmp.push_back(cur->val);
                    if (cur->left) nextLayer.push_back(cur->left);
                    if (cur->right) nextLayer.push_back(cur->right);
                }
                leftToRight = false;
            } else {
                while (!buffer.empty()) {
                    auto cur = buffer.back();
                    buffer.pop_back();
                    tmp.push_back(cur->val);
                    if (cur->right) nextLayer.push_front(cur->right);
                    if (cur->left) nextLayer.push_front(cur->left);
                }
                leftToRight = true;
            }
            swap(buffer, nextLayer);  // O(1)时间
            res.push_back(tmp);
        }
        return res;
    }
};