class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outdu(graph.size(), 0);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int node = graph[i][j];
                outdu[i]++;
                adj[node].push_back(i);
            }
        }

        queue<int> q;
        set<int> result;
        for (int i = 0; i < graph.size(); i++) {
            if (outdu[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            result.insert(p);
            for (int i = 0; i < adj[p].size(); i++) {
                outdu[adj[p][i]]--;
                if (outdu[adj[p][i]] == 0) {
                    q.push(adj[p][i]);
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};