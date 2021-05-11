class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> colorMap;
        for (int i = 0; i < answers.size(); i++) {
            int color = answers[i];
            colorMap[color]++;
        }

        int result = 0;
        for (auto m : colorMap) {
            result += ((m.second + m.first) / (m.first + 1)) * (m.first + 1);
        }

        return result;
    }
};
