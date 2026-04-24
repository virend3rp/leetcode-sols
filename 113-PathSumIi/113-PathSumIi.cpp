// Last updated: 4/24/2026, 10:15:46 PM
class Solution {
public:
    vector<vector<int>> final;  // Corrected declaration

    void allPaths(TreeNode* root, int target, vector<int> arr) {
        if (root == nullptr) return;  // Base case for recursion
        
        arr.push_back(root->val);  // Add the current node value to the path
        
        // If it's a leaf node and the target is 0, we add the current path to the result
        if (target == root->val && root->left == nullptr && root->right == nullptr) {
            final.push_back(arr);
        }
        
        // Recur for both left and right subtrees, reducing the target by the current node's value
        if (root->left) allPaths(root->left, target - root->val, arr);
        if (root->right) allPaths(root->right, target - root->val, arr);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        allPaths(root, targetSum, {});  // Start the recursion with an empty path
        return final;  // Return the final result directly
    }
};
