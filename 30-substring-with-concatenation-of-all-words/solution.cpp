class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> wordMap;
        int wordNum = words.size();
        int wordLen = words[0].length();
        int subStrLen = wordNum * wordLen;

        for (auto word : words) {
            wordMap[word]++;
        }


        for (int i = 0; i < (s.length() - subStrLen + 1); i++) {
            unordered_map<string, int> tempWordMap = wordMap;
            int j = i;
            for (; j < (i + subStrLen); j += wordLen) {
                string word = s.substr(j, wordLen);
                if (tempWordMap.count(word) == 0) {
                    break;
                }

                tempWordMap[word]--;
                if (tempWordMap[word] == 0) {
                    tempWordMap.erase(word);
                }
            }
            
            if (j == i + subStrLen && tempWordMap.empty()) {
                result.push_back(i);
            }
        }

        return result;
    }
};
