class Solution {
public:
    int kSimilarity(string s1, string s2) {
        unordered_set<string> visted;
        unordered_set<string> wordSet;
        wordSet.insert(s1);
        visted.insert(s1);

        if (s1 == s2) {
            return 0;
        }
        
        int level = 0;
        while (!wordSet.empty()) {
            unordered_set<string> newSet;
            for (auto it = wordSet.begin(); it != wordSet.end(); it++) {
                auto word = *it;
                int i = 0;
                while (word[i] == s2[i]) {
                    i++;
                }

                int old1 = word[i];
                int len = word.length();
                for (int j = i + 1; j < len; j++) {
                     // 剪枝，每次操作仅交换首个不相等的字符
                     // 如果待交换的字符和目标字符串相同位置的字符相等，则跳过
                     // 如果交换后该位置的字符还是和目标字符串相同位置的字符不相等，则跳过
                    if (word[j] == s2[j] || word[j] != s2[i]) {
                        continue;
                    }

                    auto newWord = swapChar(word, i, j);
                    if (newWord == s2) {
                        return level + 1;
                    }

                    if (visted.count(newWord)) {
                        continue;
                    }

                    newSet.insert(newWord);
                    visted.insert(newWord);
                }
            }

            level++;
            wordSet = newSet;
        }

        return 0;
    }


private:
    string swapChar(string str, int i, int j) {
        string newStr = str;
        char temp = newStr[i];
        newStr[i] = newStr[j];
        newStr[j] = temp;
        return newStr;
    }
};
