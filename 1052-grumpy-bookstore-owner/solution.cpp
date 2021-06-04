class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int len = customers.size();
        int left = 0;
        int right = 0;
        int start = 0;
        int end = 0;
        int count = 0;
        int maxCount = 0;
        int maxPeople = 0;

        while (right < len) {
            if (grumpy[right] == 0) {
                maxPeople += customers[right];
            } else {
                count += customers[right];
            }

            right++;

            if (right - left > minutes) {
                if (grumpy[left] == 1) {
                    count -= customers[left];
                }
                
                left++;
            }

            if (count > maxCount) {
                start = left;
                end = right-1;
                maxCount = count;
            }
        }

        for (int i = start; i <= end; i++) {
            if (grumpy[i] == 1) {
                maxPeople += customers[i];
            }
        }

        return maxPeople;
    }
};
