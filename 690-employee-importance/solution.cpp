/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sumImportance = 0;
        unordered_map<int, int> idxMap;
        for (int i = 0; i < employees.size(); i++) {
            idxMap[employees[i]->id] = i;
        }

        queue<int> q;
        q.emplace(id);
        sumImportance += employees[idxMap[id]]->importance;

        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                for (auto subid : employees[idxMap[p]]->subordinates) {
                    sumImportance += employees[idxMap[subid]]->importance;
                    q.emplace(subid);
                }
            }
        }

        return sumImportance;
    }
};