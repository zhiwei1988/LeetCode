class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int routeNums = routes.size();
        vector<bool> visted(routeNums, false);
        unordered_map<int, vector<int>> busInRoutes; // 公交车与线路的映射关系
        for (int i = 0; i < routeNums; i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                busInRoutes[routes[i][j]].push_back(i);
            }
        }

        if (source == target && !busInRoutes[source].empty()) {
            return 0;
        }

        queue<int> q;
        for (int i = 0; i < busInRoutes[source].size(); i++) {
            q.push(busInRoutes[source][i]);
            visted[busInRoutes[source][i]] = true;
        }

        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            step++;
            for (int i = 0; i < n; i++) {
                auto route = routes[q.front()];
                q.pop();
                for (int j = 0; j < route.size(); j++) { // 遍历某条线路中的所有公交车
                    int bus = route[j];
                    if (bus == target) {
                        return step;
                    }

                    for (int k = 0; k < busInRoutes[bus].size(); k++) {
                        int route1 = busInRoutes[bus][k];
                        if (visted[route1]) {
                            continue;
                        }

                        q.push(route1);
                        visted[route1] = true;
                    }
                }
            }
        }

        return -1;
    }
};
