class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> geneticSet(bank.begin(), bank.end());
        unordered_set<string> beginSet;
        beginSet.insert(start);
        unordered_set<string> endSet;
        endSet.insert(end);
        unordered_set<string> visted;

        if (!geneticSet.count(end)) {
            return -1;
        }

        int level = 0;
        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                std::swap(beginSet, endSet);
            }
            
            unordered_set<string> newSet;
            for (auto it = beginSet.begin(); it != beginSet.end(); it++) {
                auto genetic = *it;
                int len = genetic.length();
                for (int i = 0; i < len; i++) {
                    int old = genetic[i];
                    for (auto c : charSet) {
                        genetic[i] = c;
                        if (!geneticSet.count(genetic)) {
                            continue;
                        }

                        if (endSet.count(genetic)) {
                            return level + 1;
                        }

                        if (visted.count(genetic)) {
                            continue;
                        }

                        newSet.insert(genetic);
                        visted.insert(genetic);
                    }
                    genetic[i] = old;
                }
            }

            level++;
            beginSet = newSet;
        }

        return -1;
    }

private:
    vector<char> charSet {'A', 'C', 'G', 'T'};
};