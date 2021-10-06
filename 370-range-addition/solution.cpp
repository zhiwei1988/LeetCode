class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // 使用差分数列
        vector<int> serien(length, 0);
        for (const auto &action : updates) {
            int start = action[0];
            int end = action[1];
            int inc = action[2];
            serien[start] += inc;
            if (end + 1 < length) {
                serien[end+1] -= inc;
            }
        }

        vector<int> result(length, 0);
        partial_sum(serien.begin(), serien.end(), result.begin());
        return result;
    }
};
