class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> beginSet;
        beginSet.insert(beginWord);
        unordered_set<string> endSet;
        endSet.insert(endWord);
        unordered_set<string> visted;

        if (!wordSet.count(endWord)) {
            return 0;
        }

        int level = 1;
        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                auto tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }

            unordered_set<string> newSet;
            for (auto it = beginSet.begin(); it != beginSet.end(); it++) {
                auto word = *it;
                int len = word.length();
                for (int i = 0; i < len; i++) {
                    int old = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (!wordSet.count(word)) {
                            continue;
                        }

                        if (endSet.count(word)) {
                            return level + 1;
                        }

                        if (visted.count(word)) {
                            continue;
                        }

                        newSet.insert(word);
                        visted.insert(word);
                    }
                    word[i] = old;
                }
            }

            level++;
            beginSet = newSet;
        }

        return 0;
    }
};