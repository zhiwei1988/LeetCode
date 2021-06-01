class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        set<string> visted; //用于减枝，没有可能会进入死循环
        int step = 0;

        q.push("0000");
        for (auto m : deadends) visted.insert(m);
        if (0 != visted.count("0000")) return -1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto m = q.front();
                q.pop();
                if (m == target) return step;
                int len = m.length();
                for (int j = 0; j < len; j++) {
                    auto number = plusOne(j, m);
                    if (0 == visted.count(number)) {
                        q.push(number);
                        visted.insert(number);
                    }

                    number = minusOne(j, m);
                    if (0 == visted.count(number)) {
                        q.push(number);
                        visted.insert(number);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    string plusOne(int pos, string sequence) {
        if (sequence[pos] == '9') {
            sequence[pos] = '0';
        } else {
            sequence[pos]++;
        }

        return sequence;
    }

    string minusOne(int pos, string sequence) {
         if (sequence[pos] == '0') {
            sequence[pos] = '9';
        } else {
            sequence[pos]--;
        }

        return sequence;
    }
};
