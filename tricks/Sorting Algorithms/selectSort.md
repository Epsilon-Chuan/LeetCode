# Select Sort

## Code

```C++
#include <vector>
using namespace std;

void selectSort(vector<int>& arr)
{
    // 选择排序将序列分为无序的前缀和有序的后缀,且前缀中的所有元素都比后缀中的元素要小
    // 每次选择前缀中的最大值,然后插入后缀的首元素之前即可
    for (long i = arr.size() - 1; i >= 0; --i) {
        int max = arr[i]; // 先假定无序前缀的最大值为其最后一个元素
        long rank = i; // 最大值对应的秩
        for (long j = 0; j < i; j++) // 在无序前缀中寻找真正的最大值
            if (arr[j] >= max) {
                max = arr[j];
                rank = j;
            }
        swap(arr[rank], arr[i]); // 更新
    }
}
```
