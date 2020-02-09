class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a', 'b', 'c'};
        d[3] = {'d', 'e', 'f'};
        d[4] = {'g', 'h', 'i'};
        d[5] = {'j', 'k', 'l'};
        d[6] = {'m', 'n', 'o'};
        d[7] = {'p', 'q', 'r', 's'};
        d[8] = {'t', 'u', 'v'};
        d[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans{""};
        for (const char digit : digits) {
            vector<string> temp;
            for (const string s : ans) {
                for (const char c : d[digit - '0']) {
                    temp.push_back(s + c);
                }
            }
            ans.swap(temp);
        }

        return ans;
    }
};
