// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty()) return vector<string>{};
        sort(str.begin(), str.end());
        vector<string> res;
        string cur;
        vector<bool> used(str.size(), false);
        helper(res, cur, used, str);
        return res;
    }
    void helper(vector<string>& res, string& cur, vector<bool>& used,
                const string& str) {
        if (cur.size() == str.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < used.size(); ++i) {
            // 处理重复字母(why???!!!)
            if (i > 0 && str[i] == str[i - 1] && used[i - 1]) continue;
            if (!used[i]) {
                cur.push_back(str[i]);
                used[i] = true;
                helper(res, cur, used, str);
                cur.pop_back();
                used[i] = false;
            }
        }
    }
};