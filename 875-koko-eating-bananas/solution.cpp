class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            int cost = 0;
            for (int i = 0; i < piles.size(); i++) {
                cost += piles[i] / mid + ((piles[i] % mid == 0) ? 0 : 1);
            }

            // 速度越少，耗时越长
            if (cost > h) { // 需要加快速度
                left = mid + 1;
            } else { // 可以尝试继续降低速度
                right = mid - 1;
                res = min(res, mid);
            }
        }

        return res;
    }
};
