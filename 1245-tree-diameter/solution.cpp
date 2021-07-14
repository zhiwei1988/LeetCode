class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // 节点个数
        unordered_map<int, vector<int>> nodeMap;
        vector<int> du(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            nodeMap[edge[0]].emplace_back(edge[1]);
            nodeMap[edge[1]].emplace_back(edge[0]);
            du[edge[0]]++;
            du[edge[1]]++;
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (du[i] == 1) { // 叶子节点
                q.push(i);
            }
        }

        int level = 0;
        while (!q.empty()) {
            if (n <= 2) { // 一层层剥掉叶子节点后，当剩余节点数不超过 2 个时即为答案
                break;
            }
            auto size = q.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                for (auto m : nodeMap[p]) {
                    du[m]--;
                    if (du[m] == 1) {
                        q.push(m);
                    }
                }
            }

            level++;
        }

        if (q.empty()) { // 仅存在一个节点的情况，需要特殊处理
            return 0;
        } else if (q.size() == 1) {
            return 2 * level;
        } else {
            return 2 * level + 1; // 剩下的两个节点之间还有一条边
        }
    }
};