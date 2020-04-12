// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
// 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1],不能使用除法。
// 规定B[0] = A[1] * A[2] * ... * A[n-1],B[n-1] = A[0] * A[1] * ... * A[n-2];

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty()) return vector<int>{};
        int size = A.size();
        vector<int> left(size, 1), right(size, 1);
        for (int i = 1; i < size; ++i) {
            left[i] = left[i - 1] * A[i - 1];
            right[size - i - 1] = right[size - i] * A[size - i];
        }
        vector<int> res(size);
        for (int i = 0; i < size; ++i) res[i] = left[i] * right[i];
        return res;
    }
};