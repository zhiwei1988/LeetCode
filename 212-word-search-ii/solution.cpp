struct TrieNode {
    TrieNode()
    {
        children.resize(26, nullptr);
    }
    vector<TrieNode *> children;
    string word;
};

class TrieTree {
public:
    TrieTree()
    {
        root = new TrieNode();
    }

    void add(string word)
    {
        auto node = root;
        for (auto c : word) {
            if (node->children[c-'a'] == nullptr) {
                node->children[c-'a'] = new TrieNode();
            }

            node = node->children[c-'a'];
        }

        node->word = word;
    }

    TrieNode *root = nullptr;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto word : words) {
            tree.add(word);
        }

        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string str;
                dfs(board, tree.root, i, j);
            }
        }

        return vector<string>(strSet.begin(), strSet.end());
    }
private:
    void dfs(vector<vector<char>>& board, TrieNode *node, int x, int y)
    {
        if (!InBoard(board, x, y)) {
            return;
        }

        char ch = board[x][y];

        if (ch == '#') {
            return;
        }

        if (node->children[ch - 'a'] == nullptr) {
            return;
        }

        node = node->children[ch - 'a'];
        if (node->word != "") {
            strSet.insert(node->word);
        }

        board[x][y] = '#';
        for (auto &dir : directions) {
            int x1 = x + dir[0];
            int y1 = y + dir[1];
            dfs(board, node, x1, y1);
        }
        board[x][y] = ch;
    }

    bool InBoard(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return false;
        }

        return true;
    }
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    TrieTree tree;
    unordered_set<string> strSet;
};
