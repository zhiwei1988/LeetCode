class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
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
        }

        if (q.empty()) { // 仅存在一个节点的情况，需要特殊处理
            return {0};
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }

private:
    int bfs(int root, unordered_map<int, vector<int>> &nodeMap)
    {
        unordered_set<int> visetd;
        queue<int> q;
        q.emplace(root);
        visetd.emplace(root);

        int height = 0;
        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                for (auto m : nodeMap[p]) {
                    if (visetd.count(m)) {
                        continue;
                    }
                    q.emplace(m);
                    visetd.emplace(m);
                }
            }

            height++;
        }

        return height-1;
    }
};