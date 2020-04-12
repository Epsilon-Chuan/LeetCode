// 请实现两个函数，分别用来序列化和反序列化二叉树。

// 序列化：把一棵二叉树按照某种遍历方式的结果以某种形式保存为字符串，
// 其可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改。
// 序列化时通过某种符号表示空节点（#）,以 ！表示一个结点值的结束(value!)。

// 反序列化：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    char *Serialize(TreeNode *pRoot) {
        string s;
        if (!pRoot) return NULL;
        deque<TreeNode *> q;
        q.push_back(pRoot);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                if (q.front()) {
                    q.push_back(q.front()->left);
                    q.push_back(q.front()->right);
                    s += to_string(q.front()->val) + ' ';
                } else {
                    s += "# ";
                }
                q.pop_front();
            }
        }
        char *chr = strdup(s.c_str());
        return chr;
    }
    TreeNode *Deserialize(char *str) {
        if (!str) return nullptr;
        int k = 0;
        auto ret = nextNode(str, k);
        deque<TreeNode *> q;
        q.push_back(ret);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                q.front()->left = nextNode(str, k);
                q.front()->right = nextNode(str, k);
                if (q.front()->left) q.push_back(q.front()->left);
                if (q.front()->right) q.push_back(q.front()->right);
                q.pop_front();
            }
        }
        return ret;
    }
    TreeNode *nextNode(char *str, int &i) {
        string s;
        while (str[i] != '\0' && str[i] != ' ') {
            if (str[i] == '#') {
                i += 2;
                return nullptr;
            }
            s += str[i];
            i++;
        }
        if (str[i] == ' ') i++;
        if (!s.empty()) return new TreeNode(stoi(s));
        return nullptr;
    }
};