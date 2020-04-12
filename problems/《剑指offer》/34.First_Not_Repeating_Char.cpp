// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中,
// 找到第一个只出现一次的字符,并返回它的位置,如果没有则返回-1.
// 注意需要区分大小写

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int types = 128;
        vector<int> times(types, 0), locs(types, -1);
        for (int i = 0; i < str.size(); ++i) {
            int hashInd = str[i] - 'A';
            ++times[hashInd];
            if (locs[hashInd] == -1) locs[hashInd] = i;
        }
        int res = INT_MAX;
        for (int i = 0; i < types; ++i) {
            if (times[i] == 1) res = min(locs[i], res);
        }
        return res == INT_MAX ? -1 : res;
    }
};