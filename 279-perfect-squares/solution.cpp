class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquare(101, 0);
        vector<bool> visted(n, false);
        int res = 0;
        for (int i = 1; i < 101; i++) {
            perfectSquare[i] = i * i;
        }

        queue<int> sumQueue;
        for (int i = 1; i < 101; i++) {
            if (perfectSquare[i] > n) {
                break;
            }

            res = 1;

            if (perfectSquare[i] == n) {
                return res;
            }
            
            visted[perfectSquare[i]] = true;
            sumQueue.push(perfectSquare[i]);
        }

        while (!sumQueue.empty()) {
            size_t qSize = sumQueue.size();
            for (int i = 0; i < qSize; i++) {
                int sum = sumQueue.front();
                sumQueue.pop();
                for (int j = 0; j < 101; j++) {
                    int tmp = sum + perfectSquare[j];
                    if (tmp == n) {
                        res++;
                        return res;
                    }

                    if (tmp > n) {
                        break;
                    }

                    if (visted[tmp]) {
                        continue;
                    }

                    sumQueue.push(tmp);
                    visted[tmp] = true;
                }
            }
            res++;
        }

        return res;
    }
};
