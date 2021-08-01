class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int oneNum = 0;
        int zeroNum = 0;

        int maxNum = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                oneNum++;
            } else {
                zeroNum++;
            }

            if (zeroNum <= 1) {
                if (zeroNum == 0) {
                    maxNum = max(maxNum, oneNum);
                } else {
                    maxNum = max(maxNum, oneNum+1);
                }
            }

            right++;

            if (zeroNum > 1)  {
                if (nums[left] == 0) {
                    zeroNum--;
                } else {
                    oneNum--;
                }

                left++;
            }
        }

        return maxNum;
    }
};