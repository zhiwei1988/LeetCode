class Solution {
public:
    int minSwaps(vector<int>& data) {
        int oneNums = 0;
        int switchCnt = 0;
        int minSwitchCnt = INT_MAX;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == 1) {
                oneNums++;
            }
        }

        int oneCount = 0;
        for (int i = 0; i < oneNums; i++) {
            if (data[i] == 1) {
                oneCount++;
            }
        }

        switchCnt = oneNums - oneCount;
        minSwitchCnt = min(minSwitchCnt, switchCnt);

        for (int i = oneNums; i < data.size(); i++) {
            if (data[i] == 1) {
                oneCount++;
            }

            if (data[i-oneNums] == 1) {
                oneCount--;
            }

            switchCnt = oneNums - oneCount;
            minSwitchCnt = min(minSwitchCnt, switchCnt);
        }

        return minSwitchCnt;
    }
};