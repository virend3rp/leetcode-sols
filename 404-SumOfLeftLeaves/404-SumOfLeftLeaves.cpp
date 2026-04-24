// Last updated: 4/24/2026, 10:13:14 PM
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }

        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
