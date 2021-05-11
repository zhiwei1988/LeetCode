class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monotonicStack;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            if (monotonicStack.empty()) {
                monotonicStack.push(i);
            } else {
                int topValue = monotonicStack.top();
                if (temperatures[i] <= temperatures[topValue]) {
                    monotonicStack.push(i);
                } else {
                    while (temperatures[i] > temperatures[topValue]) {
                        result[topValue] = i - topValue;
                        monotonicStack.pop();
                        if (monotonicStack.empty()) {
                            break;
                        }
                        topValue = monotonicStack.top();
                    }

                    monotonicStack.push(i);
                }       
            }
        }

        return result;
    }
};
