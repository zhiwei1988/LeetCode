class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        auto arrSize = arr.size();
        unordered_set<int> visted;
        queue<int> q;
        q.emplace(start);

        while (!q.empty()) {
            if (visted.count(q.front())) {
                q.pop();
                continue;
            }

            auto pos = q.front();
            q.pop();
            if (pos < 0 || pos >= arrSize) {
                continue;
            }

            visted.emplace(pos);

            if (arr[pos] == 0) {
                return true;
            }

            q.emplace(pos + arr[pos]);
            q.emplace(pos - arr[pos]);
        }

        return false;
    }
};