class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int right = 1;
        int count = 1;
        int maxCount = 1;
        char last = 'z';

        while (right < arr.size()) {
            int value1 = arr[right];
            int value2 = arr[right-1];
            right++;
            
            count++;
            char now;
            if (value2 > value1) {
                now = '>';
            } else if (value2 < value1) {
                now = '<';
            } else {
                now = '=';
            }

            if (now != last && now != '=' && last != '=') {
                maxCount = max(maxCount, count);
            } else {
                // 出现不满足条件的情况时，重置 count
                count = 2;
            }

            last = now;
        }

        return maxCount;
    }
};
