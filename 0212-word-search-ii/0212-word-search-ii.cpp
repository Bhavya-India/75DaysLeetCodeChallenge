class TrieNode {
public:
    TrieNode* children[26];
    string word = "";

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:

    vector<string> result;

    void insertWord(TrieNode* root, string word) {

        TrieNode* node = root;

        for (char c : word) {

            int index = c - 'a';

            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int row,
             int col,
             TrieNode* node) {

        char c = board[row][col];

        if (c == '#' || node->children[c - 'a'] == NULL)
            return;

        node = node->children[c - 'a'];

        // Found word
        if (node->word != "") {

            result.push_back(node->word);

            node->word = "";
        }

        board[row][col] = '#';

        int directions[4][2] = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        for (auto& dir : directions) {

            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 &&
                newRow < board.size() &&
                newCol >= 0 &&
                newCol < board[0].size()) {

                dfs(board, newRow, newCol, node);
            }
        }

        board[row][col] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for (string word : words) {
            insertWord(root, word);
        }

        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[0].size(); j++) {

                dfs(board, i, j, root);
            }
        }

        return result;
    }
};