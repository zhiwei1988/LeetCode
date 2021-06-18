class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> prereq; // 每门课的前置课程数
        unordered_map<int, vector<int>> afterCourse; // 每门课的后置课程列表
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            prereq[i] = 0;
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            prereq[course]++;
            afterCourse[pre].push_back(course);
        }

        queue<int> readyQueue;

        for (auto &member : prereq) {
            if (member.second == 0) {
                readyQueue.push(member.first);
            }
        }

        while (!readyQueue.empty()) {
            auto size = readyQueue.size();
            for (int i = 0; i < size; i++) {
                int course = readyQueue.front();
                cnt++;
                readyQueue.pop();
                for (int i = 0; i < afterCourse[course].size(); i++) {
                    prereq[afterCourse[course][i]]--;
                    if (prereq[afterCourse[course][i]] == 0) {
                        // 当一门课没有前置课程时，即可放入可学习课程列表
                        readyQueue.push(afterCourse[course][i]);
                    }
                }
            }
        }

        return cnt == numCourses ? true : false;
    }
};
