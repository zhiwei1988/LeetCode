class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        std::sort(begin(nums1), end(nums1)); // 从小到大排序
        
        auto func = [](vector<int> &left, vector<int> &right) {
            return left[1] < right[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(func)> maxq(func);

        for (int i = 0; i < nums2.size(); i++) {
            // 从大到小排列
            maxq.push(vector<int>{i, nums2[i]});
        }

        int left = 0;
        int right = nums1.size() - 1;
        vector<int> res(nums1.size(), 0);
        while (!maxq.empty()) {
            auto qm = maxq.top();
            maxq.pop(); 
            cout << "qm[1] = " << qm[1] << endl;
            if (nums1[right] > qm[1]) {
                // num1[right] 自己上 
                res[qm[0]] = nums1[right--];
            } else {
                // 找个最小值应付下
                res[qm[0]] = nums1[left++];
            }
        }

        return res;   
    }
};
