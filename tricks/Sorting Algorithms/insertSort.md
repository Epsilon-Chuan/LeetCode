# Insert Sort

## Code

```C++
#include <vector>
using namespace std;

void insertSort(vector<int>& arr)
{
    // 插入排序将序列分为已排序的前缀和未排序的后缀
    // 插入排序每次从后缀中选取一个元素,然后将其插入已有序的前缀
    for (long i = 1; i < arr.size(); i++) {
        // arr[i] denotes the current target to be inserted into the sorted prefix
        int target = arr[i];
        long j = i - 1; // j moves in the sorted prefix from the maximum to minimum
        while (j >= 0)
            if (target < arr[j]) { // 如果待插入对象target位于arr[j]左侧,应继续移动
                arr[j + 1] = arr[j];
                --j;
            } else
                break; // 已找到待插入对象应该插入的位置
        arr[j + 1] = target;
    }
}
```
