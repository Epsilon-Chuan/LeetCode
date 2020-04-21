// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) return 0;
        int lo = 0, hi = rotateArray.size() - 1;
        while (lo < hi) {
            // 确保这还是个旋转数组,因为++lo之后可能造成已经非旋转数组,唯有如此后续逻辑才对
            if (rotateArray[lo] < rotateArray[hi]) break;

            int mi = (lo + hi) / 2;
            if (rotateArray[lo] < rotateArray[mi])
                lo = mi + 1;
            else if (rotateArray[mi] < rotateArray[hi])
                hi = mi;
            else
                ++lo;
        }
        return rotateArray[lo];
    }
};