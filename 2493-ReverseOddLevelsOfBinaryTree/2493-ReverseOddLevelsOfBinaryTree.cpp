// Last updated: 4/24/2026, 10:06:17 PM
class Solution {
public:
    void reverseOddLevelsHelper(TreeNode* left, TreeNode* right, int level) {
        // Base case: if either node is NULL, return
        if (left == NULL || right == NULL) {
            return;
        }

        // If the current level is odd, swap the values
        if (level % 2 != 0) {
            swap(left->val, right->val);
        }

        // Recur for the next level
        reverseOddLevelsHelper(left->left, right->right, level + 1);
        reverseOddLevelsHelper(left->right, right->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        // Call the helper function with the root's children
        reverseOddLevelsHelper(root->left, root->right, 1); // Start with level 1
        return root;
    }
};
