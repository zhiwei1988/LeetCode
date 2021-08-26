class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size = arr.size();
        if (x <= arr[0]) {
            return vector<int>{arr.begin(), arr.begin()+k};
        }

        if (x >= arr[size-1]) {
            return vector<int>{arr.end()-k, arr.end()};
        }
        
        int left = 0;
        int right = 0;
        auto lowerbound = std::lower_bound(arr.begin(), arr.end(), x);
        if (*lowerbound == x) {
            // x 为 arr 中的元素
            left = lowerbound - arr.begin() - k + 1;
            right = lowerbound - arr.begin() + k - 1;
        } else {
            lowerbound--;
            auto upperbound = std::upper_bound(arr.begin(), arr.end(), x);
            if (x - *lowerbound > *upperbound - x) {
                left = upperbound - arr.begin() - k + 1;
                right = upperbound - arr.begin() + k - 1;
            } else {
                left = lowerbound - arr.begin() - k + 1;
                right = lowerbound - arr.begin() + k - 1;
            }
        }

        if (left < 0) {
            left = 0;
        }

        if (right >= size) {
            right = size - 1;
        }

        while (right - left > k - 1) {
            if ((x - arr[left]) > (arr[right] - x)) {
                // 因为在 dis 相等的情况下 left 要优先于 rightright
                // 所以仅当之差相等时优先取左边的值
                left++;
            } else {
                right--;
            }
        }

        return vector<int>{arr.begin() + left, arr.begin() + right + 1};
    }
};
