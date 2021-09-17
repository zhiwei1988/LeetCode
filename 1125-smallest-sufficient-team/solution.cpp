class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
    {
        unordered_map<string, int> skillMap; // 某个技能在技能组合中位置
        unordered_map<int, vector<int>> skillCombMap; // 保存技能组合与people组合的映射关系
        int n = req_skills.size();
        skillCombMap.reserve(1 << n); // avoid hash refresh
        skillCombMap[0] = {};

        for (int i = 0; i < n; ++i) {
            skillMap[req_skills[i]] = i;
        }

        for (int i = 0; i < people.size(); i++) {
            int curSkillComb = 0;
            for (int j = 0; j < people[i].size(); j++) {
                curSkillComb |= 1 << skillMap[people[i][j]];
            }

            for (auto &skillComb : skillCombMap) {
                int newSkillComb = skillComb.first | curSkillComb;
                if (!skillCombMap.count(newSkillComb) ||
                    skillCombMap[newSkillComb].size() > skillCombMap[skillComb.first].size() + 1) {
                    // 如果该技能组合还没出现过，组合中人员的个数比之前少
                    // 则更新对应的技能组合所需要的人员组合
                    skillCombMap[newSkillComb] = skillCombMap[skillComb.first];
                    skillCombMap[newSkillComb].push_back(i);
                }
            }
        }

        return skillCombMap[(1 << n) - 1];
    }
};
