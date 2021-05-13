class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> memo(ring.size(), vector<int>(key.size(), 0));
        for (int i = 0; i < ring.size(); i++) {
            charMap[ring[i]].push_back(i);
        }

        return dp(ring, 0, key, 0, memo);
    }

private:
    // 求当前转盘指针处于 i 位置时，要拼出字符串 key[j...] 的最小步数
    int dp(string ring, int i, string key, int j, vector<vector<int>> &memo) {
        if (j == key.size()) {
            // 已经拼出目标字符串
            return 0;
        }

        if (memo[i][j] != 0) {
            return memo[i][j]; // 避免重复子问题
        }

        int n = ring.size();
        int res = INT_MAX;
        for (auto m : charMap[key[j]]) {
            int delta = abs(m-i); // 顺时针转
            delta = min(delta, n - delta); // 比较顺时针和逆时针哪个步数最小
            int subProblem = dp(ring, m, key, j+1, memo);
            res = min(res, 1+delta+subProblem); // 结合子问题的结果才能得出最小值
        }

        memo[i][j] = res;
        return res;
    }

    unordered_map<char, vector<int>> charMap; // 转盘中的字符与其所处位置的映射关系
};
