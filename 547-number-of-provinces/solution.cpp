class Graph {
    public:
        Graph(int v) 
        {
            m_v = v;
            m_e = 0;
            for (int i = 0; i < v; i++) {
                m_adj.push_back(set<int> {});
            }
        }

        int getV() { return m_v; }

        int getE() { return m_e; }

        // 添加一条边
        void addEdge(int v, int w)
        {
            m_adj[v].insert(w);
            m_adj[w].insert(v);
            m_e++;
        }

        // 获取和 v 相邻的所有顶点
        set<int> adj(int v)
        {
            return m_adj[v];
        }
    private:
        int m_v; // 顶点数
        int m_e; // 边的数目
        vector<set<int>> m_adj; // 邻接表
};

class CC {
    public:
        CC(Graph g)
            : m_marked(g.getV(), false),
              m_count(0)
        {
            for (int i = 0; i < g.getV(); i++) {
                if (!m_marked[i]) {
                    dfs(g, i);
                    m_count++;
                }
            }
        }

        int count() {
            return m_count;
        }

    private:
        void dfs(Graph &g, int v)
        {
            m_marked[v] = true;
            for (auto m : g.adj(v)) {
                if (!m_marked[m]) {
                    dfs(g, m);
                }
            }
        }
        int m_count; // 连通分量个数
        vector<bool> m_marked;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        Graph g(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (i != j && isConnected[i][j] == 1) {
                    g.addEdge(i, j);
                }
            }
        }

        CC c(g);
    
        return c.count();
    }
};
