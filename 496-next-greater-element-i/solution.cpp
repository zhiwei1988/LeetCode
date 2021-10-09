class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap; // 记录 x 及右边第1个比 x 大的值
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // 维持单调栈的属性（单调递增栈）
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }

            // 得到结果
            if (s.empty()) {
                hashMap[nums2[i]] = -1;
            } else {
                hashMap[nums2[i]] = s.top();
            }

            // 入栈
            s.push(nums2[i]);
        }

        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(hashMap[nums1[i]]);
        }

        return result;
    }
};
