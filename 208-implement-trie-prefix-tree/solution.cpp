class Trie {
public:
    Trie() {

    }

    void insert(string word) {
        auto *node = &rootNode;
        for (auto c : word) {
            if (!node->nodes.count(c)) {
                node->nodes[c] = new TrieNode();
            }
            node = node->nodes[c];
        }

        node->isWord = true;
    }

    bool search(string word) {
        auto *node = &rootNode;
        for (auto c : word) {
            if (!node->nodes.count(c)) {
                return false;
            }
            node = node->nodes[c];
        }

        return node->isWord;
    }

    bool startsWith(string prefix) {
        auto *node = &rootNode;
        for (auto c : prefix) {
            if (!node->nodes.count(c)) {
                return false;
            }
            node = node->nodes[c];
        }

        return true;
    }

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> nodes;
        bool isWord = false;
    };

    TrieNode rootNode;
};
