class Solution {
public:
    using PII = pair<int, int>; // 表示两个水壶中国当前各自的水容量
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<PII> q;
        auto hashFuc = [](const PII &p)
        {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        };

        unordered_set<PII, decltype(hashFuc)> pairSet {0, hashFuc};
        q.emplace(0, 0);
        
        while (!q.empty()) {
            if (pairSet.count(q.front())) {
                q.pop();
                continue;
            }

            auto [remainX, remainY] = q.front();
            q.pop(); 

            pairSet.emplace(remainX, remainY);

            if ((remainX == targetCapacity) || 
                (remainY == targetCapacity) ||
                (remainX + remainY == targetCapacity)) {
                return true;
            }

            // 装满第 1 个水壶
            q.emplace(jug1Capacity, remainY);

            // 装满第 2 个水壶
            q.emplace(remainX, jug2Capacity);

            // 清空第 1 个水壶
            q.emplace(0, remainY);

            // 清空第 2 个水壶
            q.emplace(remainX, 0);

            if (remainY > (jug1Capacity - remainX)) {
                q.emplace(jug1Capacity, remainY - jug1Capacity + remainX);
            } else {
                q.emplace(remainX + remainY, 0);
            }

            if (remainX > (jug2Capacity - remainY)) {
                q.emplace(remainX - jug2Capacity + remainY, jug2Capacity);
            } else {
                q.emplace(0, remainX + remainY);
            }
        }

        return false;
    }
};