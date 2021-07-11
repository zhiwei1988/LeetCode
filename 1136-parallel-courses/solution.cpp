class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> res;
        vector<int> indu(n+1, 0); // 入度，依赖其他课程数
        vector<vector<int>> outdu(n+1, vector<int>{}); // 出度，被其他课程依赖

        for (int i = 0; i < relations.size(); i++) {
            int course = relations[i][1];
            int preCourse = relations[i][0];
            indu[course]++;
            outdu[preCourse].push_back(course);
        }

        queue<int> courseQueue;

        size_t induSize = indu.size();
        for (int i = 1; i < induSize; i++) {
            if (indu[i] == 0) {
                courseQueue.push(i);
            }
        }

        int courseNum = 0;
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
            courseNum++;
        }

        if (res.size() == n) {
            return courseNum;
        }

        return -1;
    }
};