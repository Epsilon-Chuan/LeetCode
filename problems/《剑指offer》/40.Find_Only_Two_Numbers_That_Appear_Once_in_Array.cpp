// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。

#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        int result = 0;
        for (int i = 0; i < data.size(); ++i) result ^= data[i];
        auto index_bit_1 = find_first_bit_1(result);
        *num1 = *num2 = 0;
        for (int i = 0; i < data.size(); ++i)
            is_bit_1(data[i], index_bit_1) ? (*num1) ^= data[i]
                                           : (*num2) ^= data[i];
    }
    int find_first_bit_1(int num) {
        int res = 0;
        while ((num & 1) == 0 && res < 8 * sizeof(int)) {
            num = num >> 1;
            ++res;
        }
        return res;
    }
    bool is_bit_1(int num, int index) {
        num = num >> index;
        return num & 1;
    }
};