class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indu(numCourses, 0); // 入度，依赖其他课程数
        vector<vector<int>> outdu(numCourses, vector<int>{}); // 出度，被其他课程依赖

        size_t prerequisitesNum = prerequisites.size();
        for (int i = 0; i < prerequisitesNum; i++) {
            int course = prerequisites[i][0];
            int preCourse = prerequisites[i][1];
            indu[course]++;
            outdu[preCourse].push_back(course);
        }

        queue<int> courseQueue;

        size_t induSize = indu.size();
        for (int i = 0; i < induSize; i++) {
            if (indu[i] == 0) {
                courseQueue.push(i);
            }
        }

        while (!courseQueue.empty()) {
            size_t queueSize = courseQueue.size();
            for (int i = 0; i < queueSize; i++) {
                int course = courseQueue.front();
                res.push_back(course);
                courseQueue.pop();
                for (auto m : outdu[course]) {
                    indu[m]--;
                    if (indu[m] == 0) {
                        courseQueue.push(m);
                    }
                }
            }
        }

        if (res.size() == numCourses) {
            return res;
        }

        return vector<int>{};
    }
};
