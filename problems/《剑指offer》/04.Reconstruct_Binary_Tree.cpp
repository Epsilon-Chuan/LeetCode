// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
// {1, 2, 4, 7, 3, 5, 6, 8} 和中序遍历序列{4, 7, 2, 1,5, 3, 8, 6}，
// 则重建二叉树并返回。

#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        unordered_map<int, int> map;
        for (int i = 0; i < vin.size(); ++i) map[vin[i]] = i;
        return helper(pre, map, 0, 0, pre.size());
    }

    TreeNode *helper(vector<int> &pre, unordered_map<int, int> &map,
                     int beginPre, int beginVin, int length) {
        if (length == 0) return nullptr;
        auto node = new TreeNode(pre[beginPre]);
        int index = map[pre[beginPre]];  // vin中父节点的位置
        int lengthL = index - beginVin, lengthR = length - lengthL - 1;
        node->left = helper(pre, map, beginPre + 1, beginVin, lengthL);
        node->right =
            helper(pre, map, beginPre + lengthL + 1, index + 1, lengthR);
        return node;
    }
};