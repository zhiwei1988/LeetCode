class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        long l = 0;
        long r = n;
        while (l <= r) {
            long result = l*l + r*r;
            if (result == c) {
                return true;
            } else if (result > c) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};
