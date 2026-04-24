// Last updated: 4/24/2026, 10:12:43 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<int> largestValues(TreeNode* root) {
        vector<int> answer;
        if (root == nullptr) return answer; // Handle the case where the tree is empty
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN;  // To store the max value of each level
            
            // Traverse the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Update the max value for this level
                maxVal = max(maxVal, node->val);
                
                // Push the left and right children into the queue if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add the largest value of the current level to the answer
            answer.push_back(maxVal);
        }
        
        return answer;
    }
};