class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> openBulbs; // 记录已打开的灯的位置
        for (int i = 0; i < bulbs.size(); i++) {
            auto result = openBulbs.insert(bulbs[i]);
            auto iter = result.first;
            if (iter != openBulbs.begin()) { 
                auto temp = iter;
                temp--;
                // 计算当前位置与前一个开灯位置之间关闭的灯泡个数
                if (bulbs[i] - *temp - 1 == k) { 
                    return i+1;
                }
            }

            iter++;
            if (iter != openBulbs.end()) {
                // 计算当前位置与后一个开灯位置之间关闭的灯泡个数
                if (*iter - bulbs[i] - 1 == k) {
                    return i+1;
                }
            }
        }
        return -1;
    }
};