class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        temp.resize(size);
        int left = 0;
        int right = size - 1;
        mergeSort(nums, left, right, result);
        return result;
    }

private:
    void mergeSort(vector<int> &nums, int left, int right, int &result)
    {
        if (left >= right) { // 区间内只包含一个元素，不能再细分了
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, result);
        mergeSort(nums, mid+1, right, result);

        int i = left;
        int j = mid+1;
        while (i <= mid && j <= right) {
            if ((long)nums[i] > (long)2 * nums[j]) {
                result += (mid - i + 1); //[i, mid] 区间内的元素都满足要求
                j++;
            } else {
                i++;
            }
        }

        // 执行合并
        i = left;
        j = mid+1;
        int index = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[index++] = nums[i++];
            } else {
                temp[index++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[index++] = nums[i++];
        }

        while (j <= right) {
            temp[index++] = nums[j++];
        }

        // 将 temp 中的元素赋值给 nums 中 [left, right] 区间
        index= 0;
        while (left <= right) {
            nums[left++] = temp[index++];
        }
    }

    vector<int> temp;
};
