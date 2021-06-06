class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int subarrayLen = n - k;
        int right = 0;
        int left = 0;
        int sum = 0;
        int minSubArray = INT_MAX;
        int res = 0;

        while (right < n) {
            res += cardPoints[right];
            sum += cardPoints[right];
            right++;

            if (right - left > subarrayLen) {
                sum -= cardPoints[left];
                left++;
            }

            if (right - left == subarrayLen && sum < minSubArray) {
                minSubArray = sum;
            }
        }

        return res-minSubArray;
    }
};
