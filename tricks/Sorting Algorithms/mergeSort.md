# Merge Sort

## Code

```C++
#include <vector>
using namespace std;

void merge(vector<int>&, long, long, long);           // 声明
void mergeSort(vector<int>& arr, long lo, long hi) {  // 左闭右开[lo, hi)
    if (hi - lo < 2) return;  // 单元素区间自然有序
    long mi = (lo + hi) / 2;
    mergeSort(arr, lo, mi);  // 排序左区间[lo, mi)
    mergeSort(arr, mi, hi);  // 排序右区间[mi, hi)
    merge(arr, lo, mi, hi);  // 归并
}

void merge(vector<int>& arr, long lo, long mi, long hi) {
    long frontLen = mi - lo;  // 前(左）子向量的长度
    auto frontCopy = new int[frontLen];
    for (long i = 0; i < frontLen; i++)  // 复制前（左）子向量
        frontCopy[i] = arr[lo + i];
    long i = lo, l = 0, r = mi;  // index of total, left, right vector
    while (i < hi) {
        if (r >= hi || (l < frontLen && frontCopy[l] <= arr[r]))
            arr[i++] = frontCopy[l++];
        if (l >= frontLen || (r < hi && arr[r] < frontCopy[l]))
            arr[i++] = arr[r++];
    }
    delete[] frontCopy;
}
```

> 上述merge函数中的while循环体稍显晦涩，可等效地拆解为如下三个部分：

```C++
        while (l < frontLen && r < hi) {
            if (frontCopy[l] <= arr[r])
                arr[i++] = frontCopy[l++];
            else {
                count += r - mi + 1;
                arr[i++] = arr[r++];
            }
        }
        while (l < frontLen) arr[i++] = frontCopy[l++];  // 前子向量未处理完时
        while (r < hi) arr[i++] = arr[r++];  // 后子向量未处理完时
```
