// Last updated: 4/24/2026, 10:15:55 PM
class Solution{
public:
    int height(TreeNode* root)
    {
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+ max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};