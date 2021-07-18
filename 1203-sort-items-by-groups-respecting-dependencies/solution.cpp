class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 现对 group 进行预处理，给每个不属于任何小组的项目赋值一个唯一的组
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) {
                group[i] = m;
                m++;
            }
        }

        vector<int> groupIndegree(m, 0);
        unordered_map<int, vector<int>> groupAdj;
        for (int i = 0; i < beforeItems.size(); i++) { // 建立 group 的邻接表
            auto &beforeItem = beforeItems[i];
            for (int j = 0; j < beforeItem.size(); j++) {
                if (group[i] != group[beforeItem[j]]) {
                    //cout << "indegree " << group[i] << "++" << endl;
                    groupIndegree[group[i]]++;
                    groupAdj[group[beforeItem[j]]].push_back(group[i]);
                }
            }
        }

        vector<int> itemIndegree(n, 0);
        unordered_map<int, vector<int>> itemAdj;
        for (int i = 0; i < beforeItems.size(); i++) { // 建立 item 的邻接表
            auto &beforeItem = beforeItems[i];
            for (int j = 0; j < beforeItem.size(); j++) {
                itemIndegree[i]++;
                itemAdj[beforeItem[j]].push_back(i);
            }
        }

        auto itemlist = topologicalSort(itemIndegree, itemAdj);
        if (itemlist.empty()) {
            return vector<int>{};
        }
        
        auto grouplist = topologicalSort(groupIndegree, groupAdj);
        if (grouplist.empty()) { // 有环
            return vector<int>{};
        }

        unordered_map<int, vector<int>> group2item;
        for (int i = 0; i < itemlist.size(); i++) {
            group2item[group[itemlist[i]]].push_back(itemlist[i]);
        }

        vector<int> res;
        for (int i = 0; i < grouplist.size(); i++) {
            auto group = grouplist[i]; // 用 itemitem 替换 group
            //cout << "group = " << group << endl;
            res.insert(res.end(), group2item[group].begin(), group2item[group].end());
        }

        return res;
    }

private:
    vector<int> topologicalSort(vector<int> &indegree, unordered_map<int, vector<int>> adj)
    {
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto item = q.front();
            q.pop();
            res.push_back(item);
            if (adj.count(item)) {
                for (auto it : adj[item]) {
                    indegree[it]--;
                    if (indegree[it] == 0) {
                        q.push(it);
                    }
                }
            }
        }

        if (res.size() == indegree.size()) {
            return res;
        }

        return vector<int>();
    }
};