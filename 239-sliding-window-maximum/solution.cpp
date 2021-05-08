// 单调队列
class MonotonicQueue {
public:
    // 在队列尾部插入新元素时，要删除比待插入元素小的所有元素
    // 这样可以保证，队列从头到尾的元素任意时刻都是有序的，从大到小
    void push(int n) {
        while (!q.empty() && q.back() < n) {
            q.pop_back();
        }
        q.push_back(n);
    }

    // 返回队列中最大的元素
    int max() {
        return q.front();
    }

    void pop(int n) {
        // 该元素可能已经被删除了
        if (n == q.front()) {
            q.pop_front();
        }
    }
private:
    deque<int> q;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unique_ptr<MonotonicQueue> qPtr(new MonotonicQueue());
        vector<int> res;
        int i = 0;
        int size = nums.size();

        while(i < size) {
            if (i < k - 1) {
                qPtr->push(nums[i]); // 先把队列填满
            } else {
                qPtr->push(nums[i]);
                res.push_back(qPtr->max());
                qPtr->pop(nums[i-k+1]);
            }
            i++;
        }
        return res;
    }
};
