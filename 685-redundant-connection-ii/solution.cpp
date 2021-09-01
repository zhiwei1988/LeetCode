class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> indegree(n+1, 0); // 入度
        father.resize(n+1);
        
        for (auto edge : edges) {
            indegree[edge[1]]++;
        }
        
        vector<int> remove; // 可能需要被删除的边
        for (int i = n-1; i >= 0; i--) {
            if (indegree[edges[i][1]] == 2) {
                remove.push_back(i);
            }
        }
        
        if (remove.size() > 0) { // 存在入度为2的节点
            if (isTreeAfterRemoveEdge(edges, remove[0])) {
                return edges[remove[0]];
            } else {
                return edges[remove[1]];
            }
        }
        
        return GetDeleteEdge(edges);
    }
    
private:
    // 找出那条使有向图无法构成树的边
    vector<int> GetDeleteEdge(const vector<vector<int>>& edges)
    {
        init();
        for (int i = 0; i < edges.size(); i++) {
            // 如果两个节点在还没加入并查集之前，他们已经拥有共同的根节点
            // 那么将这条边加入后，这个图一定不是树
            if (same(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            
            join(edges[i][0], edges[i][1]);
        }
        
        return vector<int>{};
    }
    
    // 删除某条边后，剩余的边是否能构成一颗树
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge)
    {
        init();
        
        for (int i = 0; i < edges.size(); i++) {
            // 如果两个节点在还没加入并查集之前，他们已经拥有共同的根节点
            // 那么将这条边加入后，这个图一定不是树
            if (i == deleteEdge) {
                continue;
            }
            if (same(edges[i][0], edges[i][1])) {
                return false;
            }
            
            join(edges[i][0], edges[i][1]);
        }
        
        return true;
    }
    
    void init() 
    {
        for (int i = 1; i <=n; i++) {
            father[i] = i;
        }    
    }
    
    // 节点 x 的根节点
    int find(int x)
    {
        return father[x] == x ? x : father[x] = find(father[x]);
    }
    
    // 将 u->v 这条边加入并查集
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) {
            return; // 这条边已经在并查集中了
        }
        
        father[v] = u;
    }
    
    // 判断两个节点的根节点是否一致
    bool same(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) {
            return true;
        }
        
        return false;
    }
    
    vector<int> father;
    int n = 0;
};
