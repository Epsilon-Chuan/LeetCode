// 请实现一个函数用来找出字符流中第一个只出现一次的字符。
// 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
// 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
// 如果当前字符流没有存在出现一次的字符，返回#字符。

#define INT_MAX 2147483647

class Solution {
public:
    // Insert one char from stringstream
    int index = 1;
    char hash[256] = {0};
    void Insert(char ch) {
        if (hash[ch] == 0) {
            hash[ch] = index;
        } else if (hash[ch] > 0) {
            hash[ch] = -1;
        }
        ++index;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        int minIndex = INT_MAX;
        char res = '#';
        for (int i = 0; i < 256; ++i) {
            if (hash[i] > 0 && hash[i] < minIndex) {
                minIndex = hash[i];
                res = char(i);
            }
        }
        return res;
    }
};