// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0

// 输入:一个字符串,包括数字字母符号,可以为空
// 输出:如果是合法的数值表达则返回该数字，否则返回0
// 示例: +2147483647 -> 2147483647, 1a33 -> 0

#include <string>
#define INT_MAX 2147483647
#define INT_MIN -INT_MAX - 1
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int sign = 1, res = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (i == 0 && str[i] == '-')
                sign = -1;
            else if (i == 0 && str[i] == '+')
                sign = 1;
            else {
                int digit = str[i] - '0';
                if (0 <= digit && digit <= 9) {
                    if (res >= INT_MAX / 10 &&
                        ((sign == 1 && digit > 7) || (sign == -1 && digit > 8)))
                        return 0;
                    res = 10 * res + digit;
                } else
                    return 0;
            }
        }
        return sign * res;
    }
};