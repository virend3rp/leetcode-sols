// Last updated: 4/24/2026, 10:12:28 PM
class Solution {
public:
    int sum = 0;

    int subtreeSum(TreeNode* root) {
        if (!root) return 0;  // Base case
        
        int leftSum = subtreeSum(root->left);  // Sum of left subtree
        int rightSum = subtreeSum(root->right); // Sum of right subtree

        int tilt = abs(leftSum - rightSum);  // Compute tilt for current node
        sum += tilt;  // Accumulate total tilt
        
        return leftSum + rightSum + root->val; // Return total sum of this subtree
    }

    int findTilt(TreeNode* root) {
        sum = 0;  // Reset sum for fresh calculation
        subtreeSum(root);
        return sum; // Return accumulated tilt
    }
};
