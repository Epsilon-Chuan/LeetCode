// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are
// Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int numOfSpace = 0, oldLength = 0, newLength;
        for (int i = 0; str[i] != '\0'; ++i) {
            ++oldLength;
            if (str[i] == ' ') ++numOfSpace;
        }
        newLength = oldLength + 2 * numOfSpace;
        if (newLength > length) return;
        // 原字符串末尾的'\0'也需要移动，所以不能从oldLength - 1开始?
        int i = oldLength, j = newLength;
        while (i > -1) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            } else
                str[j--] = str[i];
            --i;
        }
    }
};