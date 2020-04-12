// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
// 例如，如果输入如下4 X 4矩阵：1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int rows = matrix.size(), cols = matrix[0].size();
        int layer = rows < cols ? (rows + 1) / 2 : (cols + 1) / 2;
        for (int i = 0; i < layer; ++i) {
            helper(res, matrix, i, rows - i - 1, i, cols - i - 1);
        }
        return res;
    }
    void helper(vector<int>& res, vector<vector<int>>& matrix, int rlo, int rhi,
                int clo, int chi) {
        if (rlo == rhi)
            for (int j = clo; j <= chi; ++j) res.push_back(matrix[rlo][j]);
        else if (clo == chi)
            for (int i = rlo; i <= rhi; ++i) res.push_back(matrix[i][clo]);
        else {
            for (int j = clo; j <= chi; ++j) res.push_back(matrix[rlo][j]);
            for (int i = rlo + 1; i <= rhi; ++i) res.push_back(matrix[i][chi]);
            for (int j = chi - 1; j >= clo; --j) res.push_back(matrix[rhi][j]);
            for (int i = rhi - 1; i >= rlo + 1; --i)
                res.push_back(matrix[i][clo]);
        }
    }
};

int main() {
    int rows = 4, cols = 3;
    vector<vector<int>> matrix(rows);
    for (int i = 0, base = 0; i < matrix.size(); ++i)
        for (int j = 0; j < cols; ++j) {
            matrix[i].push_back(++base);
            cout << base << ends;
        }
    cout << endl;
    Solution s;
    auto seq = s.printMatrix(matrix);
    for (auto c : seq) cout << c << ends;
}