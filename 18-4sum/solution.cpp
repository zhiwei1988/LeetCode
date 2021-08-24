class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(begin(nums), end(nums));
	    vector<vector<int>> result;
	    for (int i = 0; i < nums.size(); i++)  {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            auto threeNumberSum = ThreeNumberSum(nums, i+1, nums.size(), target-nums[i]);
            for (int j = 0; j < threeNumberSum.size(); j++) {
                threeNumberSum[j].push_back(nums[i]);
                result.push_back(threeNumberSum[j]);
            }	
	    }
        return result;
    }

private:
    vector<vector<int>> ThreeNumberSum(vector<int> &array, int start, int end, int targetSum) {
        vector<vector<int>> result;
        for (int i = start; i < end; i++) {
            if (i > start && array[i] == array[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = end - 1;
            
            while (left < right) {
                long sum = (long)array[i] + array[left] + array[right];
                if (sum < targetSum) {
                    left++;
                } else if (sum > targetSum) {
                    right--;
                } else {
                    result.push_back(vector<int>{array[i], array[left], array[right]});
                    while (left < right && array[left] == array[left+1]) {
                        left++;
                    }	
                    left++;

                    while (left < right && array[right] == array[right-1]) {
                        right--;
                    }
                    right--;
                }
            }
        }
        return result;
    }
};
