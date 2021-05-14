class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> int2Str;
        string res;

        for (int i = 0; i < nums.size(); i++) {
            int2Str.push_back(to_string(nums[i]));
        }

        std::sort(begin(int2Str), end(int2Str), [](auto &a, auto &b) {
            return (a+b) > (b+a); // 返回 true 表示 a 必须在 b 前面
        });

        for (auto m : int2Str) {
            res += m;
        }

        return res[0] == '0' ? "0" : res;
    }
};
