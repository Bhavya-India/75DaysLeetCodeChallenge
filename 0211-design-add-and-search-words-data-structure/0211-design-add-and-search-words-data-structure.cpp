class WordDictionary {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    Node* root;

    bool dfs(string& word, int index, Node* node) {
        if (index == word.size())
            return node->isEnd;

        char c = word[index];

        // Case 1: Normal character
        if (c != '.') {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
                return false;
            return dfs(word, index + 1, node->children[idx]);
        }

        // Case 2: Wildcard '.'
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr)
                curr->children[idx] = new Node();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};