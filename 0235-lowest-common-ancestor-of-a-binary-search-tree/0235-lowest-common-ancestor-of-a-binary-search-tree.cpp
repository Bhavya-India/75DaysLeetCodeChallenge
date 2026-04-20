class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // Both nodes are in the right subtree
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } 
            // Both nodes are in the left subtree
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } 
            // We found the split point (or root matches p or q)
            else {
                return root;
            }
        }
        return nullptr;
    }
};
