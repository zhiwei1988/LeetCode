class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto comp = [](vector<int> &l, vector<int> &r) {
            return l[1] < r[1];
        };

        sort(courses.begin(), courses.end(), comp); // 按课程关闭时间升序排序

        priority_queue<int> pq;
        int now = 0;
        for (int i = 0; i < courses.size(); i++) {
            auto &course = courses[i];
            pq.push(course[0]);
            now += course[0];
            if (now > course[1]) {
                auto top = pq.top(); // 将之前上过的好时最长的课取消
                pq.pop();
                now -= top;
            }
        }

        return pq.size();
    }
};