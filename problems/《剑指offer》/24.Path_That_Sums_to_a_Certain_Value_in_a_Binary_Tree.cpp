// 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)

#include <algorithm>
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
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        if (!root) return vector<vector<int>>{};
        vector<vector<int>> paths;
        vector<int> path;
        helper(paths, path, root, expectNumber);
        sort(paths.begin(), paths.end(),
             [](vector<int> &a, vector<int> &b) -> bool {
                 return a.size() > b.size();
             });
        return paths;
    }
    void helper(vector<vector<int>> &paths, vector<int> &path, TreeNode *root,
                int expectNumber) {
        expectNumber -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && !expectNumber) {
            paths.push_back(path);
        }
        if (root->left) helper(paths, path, root->left, expectNumber);
        if (root->right) helper(paths, path, root->right, expectNumber);
        path.pop_back();
    }
};