// Last updated: 4/24/2026, 10:15:47 PM
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        if(!root->left&&!root->right)return root->val==targetSum;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }
};