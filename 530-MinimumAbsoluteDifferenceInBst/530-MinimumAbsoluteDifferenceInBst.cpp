// Last updated: 4/24/2026, 10:12:37 PM
class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -1; // Store previous node value (initialize to invalid value)

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left); // Visit left subtree

        // Compute absolute difference with previous node (if exists)
        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val; // Update previous node

        inorder(root->right); // Visit right subtree
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};
