class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int numOfXY = 0;
        int numOfYX = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] < s2[i]) {
                numOfXY++; // 对应 s1[i] = x 且 s2[i] = y 的场景
            } else if (s1[i] > s2[i]) {
                numOfYX++; // 对应 s1[i] = y 且 s2[i] = x 的场景
            }
        }

        // xx yy => xy xy 需要交换 1 次
        // yy xx => xy xy 需要交换 1 次
        // xy yx => xy xy 需要交换 2 次
        // 所以 numOfYX 和 numOfYX 必须都是偶数，或者两者都是奇数时才可能成功转换
        if (numOfXY % 2 - numOfYX % 2 != 0) {
            return -1;
        }

        // 优先执行 xx yy => xy xy 和 yy => xx 的转换
        // 最后执行 xy yx => xy xy 的转换（如果存在，numOfXY 为奇数）
        return numOfXY / 2 + numOfYX / 2 + numOfXY % 2 * 2;
    }
};
