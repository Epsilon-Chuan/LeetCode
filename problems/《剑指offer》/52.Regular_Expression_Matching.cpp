// 请实现一个函数用来匹配包括'.'和'*'的正则表达式。
// 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次(包含0次)。
// 在本题中，匹配是指字符串的所有字符匹配整个模式。
// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

class Solution {
public:
    bool match(char* str, char* pattern) {
        if (str == nullptr || pattern == nullptr) return false;
        if (*str == '\0' && *pattern == '\0') return true;
        if (*str != '\0' && *pattern == '\0') return false;
        if (*(pattern + 1) == '*') {
            if (*pattern == *str || (*pattern == '.' && *str != '\0'))
                return match(str + 1, pattern + 2)  // move on the next state
                       || match(str + 1, pattern)   // stay on the current state
                       || match(str, pattern + 2);  // ignore a '*'
            else
                return match(str, pattern + 2);  // ignore a '*'
        }
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match(str + 1, pattern + 1);
        return false;
    }
};