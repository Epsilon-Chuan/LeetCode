// 地上有一个m行和n列的方格。
// 一个机器人从坐标(0,0)的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
// 但是不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格(35,37)，因为3+5+3+7 = 18;
// 但是，它不能进入方格(35,38)，因为3+5+3+8 = 19.
// 请问该机器人能够达到多少个格子？
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        // 我终于做到了！！！

        _threshold = threshold, _rows = rows, _cols = cols;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        return movingCountHelper(visited, 0, 0);
    }

private:
    int _threshold, _rows, _cols;
    int movingCountHelper(vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || col < 0 || row == _rows || col == _cols)  // 越界
            return 0;
        if (forbid(row, col) || visited[row][col]) return 0;

        visited[row][col] = true;
        return 1 + movingCountHelper(visited, row, col - 1) +
               movingCountHelper(visited, row, col + 1) +
               movingCountHelper(visited, row - 1, col) +
               movingCountHelper(visited, row + 1, col);
    }
    bool forbid(int row, int col) {
        int _sum = 0;
        while (row > 0 || col > 0) {
            if (row > 0) {
                _sum += row % 10;
                row /= 10;
            }
            if (col > 0) {
                _sum += col % 10;
                col /= 10;
            }
        }
        return _sum > _threshold ? true : false;
    }
};