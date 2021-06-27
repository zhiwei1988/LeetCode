class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;

        // 构建邻接表
        vector<vector<int>> adj(n, vector<int>{});
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visted(n, false);
        for (int i = 0; i < n ; i++) {
            if (!visted[i]) {
                bfs(adj, visted, i);
                res++;
            }
        }

        return res;
    }

private:
    void bfs(vector<vector<int>> &adj, vector<bool> &visted, int i)
    {
        queue<int> nodeQueue;
        nodeQueue.push(i);
        visted[i] = true;

        while (!nodeQueue.empty()) {
            auto size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                for (int j = 0; j < adj[node].size(); j++) {
                    if (!visted[adj[node][j]]) {
                        nodeQueue.push(adj[node][j]);
                        visted[adj[node][j]] = true;
                    }
                }
            }
        }
    } 
};