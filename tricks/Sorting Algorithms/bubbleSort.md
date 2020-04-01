# Bubble Sort

## Code

```C++
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    for (long i = 0; i < arr.size(); i++) {
        bool flag = true;
        for (long j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        if (flag == true)
            return;
    }
}
```
