// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k < 1 || k > input.size()) return vector<int>{};
        int index = partition(input, 0, input.size());
        int start = 0, end = input.size();
        while (index != k) {
            if (index < k) {
                start = index + 1;
                index = partition(input, start, end);
            } else {
                end = index;
                index = partition(input, start, end);
            }
        }
        vector<int> res(k);
        cout << endl;
        for (int i = 0; i < k; ++i) {
            cout << input[i] << ends;
            res[i] = input[i];
        }
        return res;
    }
    int partition(vector<int>& input, int lo, int hi) {
        int rank = lo + rand() % (hi - lo);
        swap(input[rank], input[lo]);
        int pivot = input[lo];
        while (lo < hi - 1) {
            while (lo < hi - 1 && input[hi - 1] >= pivot) --hi;
            input[lo] = input[hi - 1];
            while (lo < hi - 1 && input[lo] <= pivot) ++lo;
            input[hi - 1] = input[lo];
        }
        input[lo] = pivot;
        cout << lo << ends;
        return lo;
    }
};

int main() {
    vector<int> input{4, 5, 1, 6, 2, 7, 3, 8};
    Solution sol;
    sol.GetLeastNumbers_Solution(input, 3);
}