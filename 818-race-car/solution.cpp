class Solution {
public:
    int racecar(int target) {
        unordered_map<int, unordered_map<int, bool>> visted;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 1));
        visted[0][1] = true;
        int speed = 1;
        int step = 0;
        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                if (temp.first == target) {
                    return step;
                }
                
                
                for (int i = 0; i < 2; i++) {
                    int pos = 0;
                    int speed = 0;
                    if (i == 0) {
                        pos = temp.first + temp.second;
                        speed = 2 * temp.second;
                    } else {
                        pos = temp.first;
                        if (temp.second > 0) {
                            speed = -1;
                        } else {
                            speed = 1;
                        }
                    }
                    
                    if ((visted.count(pos) == 0 || visted[pos].count(speed) == 0) 
                        && pos > 0 && (pos < 2 * target)) { // 剪枝
                        q.push(make_pair(pos, speed));
                        visted[pos][speed] = true;
                    }
                }
            }
            
            step++;
        }
        
        return INT_MAX;
    }
};
