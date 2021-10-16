class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        int left = 1;
        int right = citations.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            auto pos = lower_bound(citations.begin(), citations.end(), mid);
            int num = citations.size() - (pos - citations.begin());
            if (num == mid) {
                left = mid + 1;
            } else if (num > mid) {
                left = mid + 1;
            } else {
                right= mid - 1;
            }
        }

        return right;
    }
};
