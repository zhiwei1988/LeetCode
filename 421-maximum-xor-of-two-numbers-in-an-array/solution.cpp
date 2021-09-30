struct TrieNode {
    TrieNode() {
        children.resize(2, nullptr);
    }
    vector<TrieNode *> children;
};

struct BitwiseTree {
    BitwiseTree() {
        root = new TrieNode();
    }

    void add(int num) {
        auto node = root;
        for (int i = 31; i >= 0; i--) {
            int cur = num >> i & 0x01;
            if (node->children[cur] == nullptr) {
                node->children[cur] = new TrieNode();
            }
            node = node->children[cur];
        }
    }

    int getMaxinumXOR(int num) {
        auto node = root;
        int sum = 0;
        for (int i = 31; i >= 0; i--) {
            int cur = num >> i & 0x01;
            int reverse = (cur == 1 ? 0 : 1);
            if (node->children[reverse] != nullptr) {
                // 如果能找到与当前 bit 相反的值，则取该相反的值，^ 之后 == 1
                sum += (1 << i);
                node = node->children[reverse];
            } else {
                node = node->children[cur];
            }
        }

        return sum;
    }

    TrieNode *root;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BitwiseTree tree;
        for (const auto &num : nums) {
            tree.add(num);
        }

        int maxOXR = INT_MIN;
        for (const auto &num : nums) {
            maxOXR = max(maxOXR, tree.getMaxinumXOR(num));
        }

        return maxOXR;
    }
};
