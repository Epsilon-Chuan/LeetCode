/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j]表示以第i行第j列为右下角所能构成的最大正方形连长, 则递推式为:
        // 当 matrix[i][j] == '0', dp[i][j] = 0; 当 matrix[i][j] == '1':
        // dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);

        if (matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size(), res = 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i)
            for (int j = 1; j <= cols; ++j)
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1]));
                    res = max(res, dp[i][j]);
                }
        return res * res;
    }
};