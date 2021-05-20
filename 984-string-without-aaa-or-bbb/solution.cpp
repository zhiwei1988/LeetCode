class Solution {
public:
    string strWithout3a3b(int a, int b) {
        char last1 = 'z';
        char last2 = 'z';
        string res;

        while (a > 0 || b > 0) {
            if (last1 != 'z' && last2 != 'z' && last1 == last2) {
                // 如果前两个字符都相同，则接下来的字符的取和它不同的
                if (last1 == 'a') {
                    res += 'b';
                    b--;
                    last1 = last2;
                    last2 = 'b';
                } else {
                    res += 'a';
                    a--;
                    last1 = last2;
                    last2 = 'a';
                }
            } else if (a >= b) {
                // 前两个字符不相等，则取剩余字符数比较多的那个字符
                res += 'a';
                a--;
                last1 = last2;
                last2 = 'a';
            } else {
                res += 'b';
                b--;
                last1 = last2;
                last2 = 'b';
            }
        }
        return res;
    }
};
