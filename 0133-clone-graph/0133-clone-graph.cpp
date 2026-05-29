/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        // If node already cloned
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create clone
        Node* clone = new Node(node->val);

        // Store in map
        mp[node] = clone;

        // Clone neighbors
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {

        if (node == NULL) {
            return NULL;
        }

        return dfs(node);
    }
};