class Solution {
public:
    priority_queue<int> small; // 大顶堆，存放小于中位数的值
    priority_queue<int, vector<int>, greater<int>> big; // 小顶堆，存放所有大于中位数的值
    unordered_map<int, int> mp; // 记录要删除的元素

    double get(int& k){
        if(k % 2 != 0) {
            // 当 K 为奇数时候，中位数是元素数量较多的 small 堆 堆顶元素。
            return small.top();
        } else {
            // 当 K 为偶数时候，中位数是 small 堆和 big 堆的堆顶元素平均值。
            return ((long long)small.top() + big.top()) * 0.5;
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) {
            small.push(nums[i]);
        };
        
        for(int i = 0; i < k / 2; i++) {
            big.push(small.top()); 
            small.pop();
        }

        vector<double> ans{get(k)};

        for(int i = k; i < nums.size(); i++) {
            // 假定在上一次滑动之后，已经有 small 堆和 big 堆元素数目相差小于等于1
            // balance 表示因本次窗口滑动导致 small 堆元素数目与 big 堆元素个数差值的增量。
            int balance = 0;
            
            // 由于堆无法直接删除掉某个指定元素，先欠下这个账，等某次元素出现在堆顶的时候，再删除他
            int left = nums[i-k]; 
            mp[left]++;

            // 虽然没有真的在堆数据结构中删除窗口最左侧的元素，但是在我们的心中已经删掉他了。
            // 堆两侧的平衡性发生了变化。
            if(!small.empty() && left <= small.top()) {
                // 删掉的元素在 small 堆中
                balance--;
            } else {
                // 删掉的元素在big堆中
                balance++;
            }

            int right = nums[i]; 
            if(!small.empty() && nums[i] <= small.top()){
                small.push(right);
                balance++;
            } else {
                big.push(right);
                balance--;
            }

            // 经过上面的操作，balance 要么为 0，要么为 2，要么为 -2。
            // 我们需要经过调整使得balance 为 0。
            if(balance > 0){
                // small 堆中的元素比 big 堆中多 2 个
                // 从small 堆减少一个，big 堆里增加一个，就可以让两边相等。
                big.push(small.top());
                small.pop();
            }

            if(balance < 0) {
                // small 堆中的元素比 big 堆中少 2 个
                // 从 big 堆减少一个，small 堆里增加一个，就可以让两边相等。
                small.push(big.top());
                big.pop();
            }

            // 调整完了，现在该欠债还钱了。不能让那些早该删除的元素涉及到中位数的运算。
            // 分别检查两边的堆顶元素，如果堆顶元素欠着债，则弹出堆顶元素，直到堆顶元素没有欠债为止。
            while(!small.empty() && mp[small.top()]>0){
                mp[small.top()]--;
                small.pop();
            }

            while(!big.empty() && mp[big.top()]>0){
                mp[big.top()]--;
                big.pop();
            }

            // 取中位数的时候只与堆顶元素有关，至于那些堆顶下面欠着债的，欠着就欠着吧，等他们到堆顶的时候再弹出去就好了。

            ans.push_back(get(k)); 
        }

        return ans;
    }
};
