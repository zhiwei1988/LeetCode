class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruitClass = 0;
        int fruitNum = 0;
        int res = 0;
        unordered_map<int, int> fruitFq;
        int start = 0;
        int end = 0;

        while (end < fruits.size()) {
            int fruit = fruits[end];
            if (fruitFq[fruit] == 0) {
                fruitClass++;
            }

            fruitFq[fruit]++;
            fruitNum++;

            while (fruitClass > 2) {
                int fruit = fruits[start];
                fruitFq[fruit]--;
                fruitNum--;
                if (fruitFq[fruit] == 0) {
                    fruitClass--;
                }

                start++;
            }

            res = max(res, fruitNum);
            end++;
        }

        return res;
    }
};