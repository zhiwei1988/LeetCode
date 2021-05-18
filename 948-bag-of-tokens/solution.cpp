class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // 按令牌能量值从低到高排序
        // 排序可以让每次消耗最少的能量，获取最多的分数；每次消耗最少的分数，获取最多的能量
        std::sort(begin(tokens), end(tokens));
        int left = 0;
        int right = tokens.size()-1;
        int count = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                // 剩余能量足以使当前令牌正面朝上时，优先使其正面朝上
                count++;
                power -= tokens[left];
                left++;
            } else if (count > 0 && left != right) {
                // 剩余能量不足以上当前令牌正面朝上，但分数不为 0
                // 使能量值最大的令牌正面朝下，以获得能量值
                count--;
                power += tokens[right];
                right--;
            } else {
                // 剩余能量不足以上当前令牌正面朝上，分数为 0
                left++;
            }
        }

        return count;
    }
};
