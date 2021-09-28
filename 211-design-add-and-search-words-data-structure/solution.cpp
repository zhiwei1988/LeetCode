class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        auto *node = root;
        for (auto c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }

            node = node->children[c];
        }

        node->isWord = true;
    }

    bool search(string word) {
        return searchHelp(word, 0, root);
    }

private:
    struct TrieNode {
        unordered_map<char, struct TrieNode *> children;
        bool isWord;
    };

    bool searchHelp(string word, int pos, TrieNode *node) {
        if (pos == word.length()) {
            return node->isWord;
        }

        auto c = word[pos];
        if (c == '.') {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (node->children.count(ch)) {
                    if (searchHelp(word, pos+1, node->children[ch])) {
                        return true;
                    }
                }
            }

            return false;
        } else {
            if (!node->children.count(c)) {
                return false;
            }

            return searchHelp(word, pos+1, node->children[c]);
        }
    }

    TrieNode *root = nullptr;
};
