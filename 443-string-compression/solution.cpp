class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        int right = 1;
        int cur = 0;
        if (chars.size() == 1) {
            return 1;
        }

        while (right < chars.size()) {
            if (chars[right] != chars[right-1]) {
                chars[cur] = chars[left];
                cur++;
                int num = right - left;
                if (num > 1) {
                    string strnum = to_string(num);
                    for (int i = 0; i < strnum.length(); i++) {                       
                        chars[cur] = strnum[i];
                        cur++;
                    }                    
                }

                left = right;
            }

            right++;
        }

        chars[cur] = chars[left];
        cur++;
        int num = right - left;
        if (num > 1) {
            string strnum = to_string(num);
            for (int i = 0; i < strnum.length(); i++) {
                chars[cur] = strnum[i];
                cur++;
            }                    
        }

        return cur;
    }
};
