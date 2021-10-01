struct DSU {
    vector<int> parent;
    vector<int> size; // size[i] 表示以 i 为根节点的集合中元素的个数
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 寻找根节点
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        parent[x] = find(parent[x]); // 路径压缩
        return parent[x];
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        } else if (px < py) {
            parent[px] = py; // 将数量少的集合合并到数量多的集合
            size[py] += size[px]; // 合并以后，集合中元素的个数也需要相加
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }

    int findMaxSize() {
        int maxSize = 0;
        for (const auto& m : size) {
            maxSize = max(maxSize, m);
        }
        return maxSize;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numsContain;
        int n = nums.size();
        DSU dsu(n);
        for (int i = 0; i < nums.size(); i++) {
            if (numsContain.count(nums[i])) {
                continue;
            }

            numsContain[nums[i]] = i;
            if (numsContain.count(nums[i]-1)) {
                // 如果存在与当前数字相邻的数字，则将它们合并
                dsu.Union(i, numsContain[nums[i]-1]);
            }

            if (numsContain.count(nums[i]+1)) {
                dsu.Union(i, numsContain[nums[i]+1]);
            }
        }

        return dsu.findMaxSize();
    }
};
