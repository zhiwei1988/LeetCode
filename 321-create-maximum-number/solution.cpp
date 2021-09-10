class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k, 0);
        int x = k - nums2.size();
        int y = nums1.size();
        int start = max(0, x);
        int end = min(y, k);
        for (int i = start; i <= end; i++) {
            auto subNums1 = getMaxSubNums(nums1, i);
            auto subNums2 = getMaxSubNums(nums2, k - i);
            auto mergedNums = mergeSubNums(subNums1, subNums2);
            if (compVector(mergedNums, 0, result, 0) > 0) {
                result = mergedNums;
            }
        }

        return result;
    }

private:
    // 获取指定长度，值最大的子串
    vector<int> getMaxSubNums(vector<int>& nums, int subLen)
    {
        int len = nums.size();
        int remain = len - subLen;
        int i= 0;
        stack<int> s;
        while (i < len) {
            while (!s.empty() && nums[s.top()] < nums[i] && remain > 0) {
                s.pop();
                remain--;
            }

            s.push(i);
            i++;
        }

        while (s.size() > subLen) {
            s.pop();
        }

        vector<int> result;
        while (!s.empty()) {
            if (result.empty()) {
                result.push_back(nums[s.top()]);
            } else {
                result.insert(result.begin(), nums[s.top()]);
            }

            s.pop();
        }


        return result;
    }

    vector<int> mergeSubNums(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (compVector(nums1, i, nums2, j) > 0) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }

    int compVector(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size()) {
            int diff = nums1[i] - nums2[j];
            if (diff != 0) {
                return diff;
            }

            i++;
            j++;
        }

        return (nums1.size() - i) - (nums2.size() - j);
    }
};
