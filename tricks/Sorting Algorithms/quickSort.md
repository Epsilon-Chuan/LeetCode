# Quick Sort

## Code

```C++
#include <vector>
using namespace std;

long partition(vector<int>&, long, long); // 声明
void quickSort(vector<int>& arr, long lo, long hi)
{
    if (hi - lo < 2) // 单元素区间自然有序
        return;
    long mi = partition(arr, lo, hi); // 在[lo, hi)内构造支(轴)点,将原向量分割为两部分
    quickSort(arr, lo, mi); // 对前缀递归排序
    quickSort(arr, mi + 1, hi); // 对后缀递归排序
}
long partition(vector<int>& arr, long lo, long hi) // 轴点构造算法
{
    // 任选一个元素与首元素交换
    long rank = lo + rand() % (hi - lo);
    swap(arr[lo], arr[rank]);

    int pivot = arr[lo]; // 以首元素为候选支(轴)点——经以上交换，等效于随机选取
    while (lo < hi - 1) {
        while (lo < hi - 1 && pivot <= arr[hi - 1])
            --hi; // 向左扩展右端子向量
        arr[lo] = arr[hi - 1];
        while (lo < hi - 1 && arr[lo] <= pivot)
            ++lo; // 向右扩展左端子向量
        arr[hi - 1] = arr[lo]; // 大于pivot者归入右侧子序列
    } // assert: lo == hi - 1
    arr[lo] = pivot; // 将备份的轴点记录置于前、后子向量之间
    return lo; // 返回轴点的秩,即母算法中需要的切分点的位置
}
```
