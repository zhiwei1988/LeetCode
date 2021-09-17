class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        m_capacity = capacity;
    }

    void push(int val) {
        if (avalidStack.empty()) {
            avalidStack.insert(stackList.size());
        }

        stackList[*avalidStack.begin()].push(val);
        if (stackList[*avalidStack.begin()].size() >= m_capacity) {
            avalidStack.erase(avalidStack.begin());
        }
    }

    int pop() {
        while (!stackList.empty() && stackList.rbegin()->second.empty()) {
            stackList.erase(stackList.rbegin()->first);
        }

        if (stackList.empty()) {
            return -1;
        }

        return popAtStack(stackList.rbegin()->first);
    }

    int popAtStack(int index) {
        if (!stackList.count(index) || stackList[index].empty()) {
            return -1;
        }

        int val = stackList[index].top();
        stackList[index].pop();
				// 如果中间某个栈空了，在有新的元素要插入时，要优先补充上
        avalidStack.insert(index);
        if (stackList[index].empty()) {
            stackList.erase(index);
        }
        return val;
    }

private:
    set<int> avalidStack; // 还能放入元素的栈索引，set 能保证索引从小达到排列
    map<int, stack<int>> stackList;
    int m_capacity;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
