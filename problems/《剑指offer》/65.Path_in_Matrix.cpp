// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
// 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
// 例如，如下矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
//          a b c e
//          s f c s
//          a d e e
// 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

#include <vector>
using namespace std;

class Solution {
public:
    int Rows, Cols;
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        Rows = rows;
        Cols = cols;
        vector<vector<bool>> visited(Rows, vector<bool>(Cols, false));
        for (int row = 0; row < Rows; ++row)
            for (int col = 0; col < Cols; ++col) {
                if (helper(matrix, str, visited, row, col, 0)) return true;
            }
        return false;
    }
    bool helper(char* matrix, char* str, vector<vector<bool>>& visited, int row,
                int col, int i) {
        // 这儿的连续三个if语句的顺序可不能反呐！
        if (str[i] == '\0') return true;
        if (row < 0 || row == Rows || col < 0 || col == Cols)  // 越界
            return false;
        if (matrix[row * Cols + col] != str[i] || visited[row][col])
            return false;

        visited[row][col] = true;
        bool flag = helper(matrix, str, visited, row, col - 1, i + 1) ||
                    helper(matrix, str, visited, row, col + 1, i + 1) ||
                    helper(matrix, str, visited, row - 1, col, i + 1) ||
                    helper(matrix, str, visited, row + 1, col, i + 1);
        if (!flag) {
            visited[row][col] = false;
            return false;
        }
        return true;
    }
};