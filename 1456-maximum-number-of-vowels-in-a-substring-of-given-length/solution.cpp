class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (vowelSet.count(s[i])) {
                count++;
            }
        }

        int maxCount = count;
        for (int i = k; i < s.length(); i++) {
            if (vowelSet.count(s[i])) {
                count++;
            }

            if (vowelSet.count(s[i-k])) {
                count--;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }

private:
    unordered_set<char> vowelSet {'a', 'e', 'i', 'o', 'u'};
};