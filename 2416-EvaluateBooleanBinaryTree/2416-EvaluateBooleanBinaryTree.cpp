// Last updated: 4/24/2026, 10:06:34 PM
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
 bool dfs(TreeNode* root) {
      if (!root) return 0;

      if(!root->left && !root->right){
        return root->val;
      }
        bool left=dfs(root->left);
        bool right=dfs(root->right);

            if(root->val==2){
                return left|right;
            }else{
                return left && right;
            }
    }
    bool evaluateTree(TreeNode* root) {
       
        return dfs(root);
        
    }
};