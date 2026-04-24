// Last updated: 4/24/2026, 10:15:34 PM
class Solution {
public:
    int maxPathSum(TreeNode *root){
    int maxi=INT_MIN;
    maxPath(root,maxi);
    return maxi;
    }
    int maxPath(TreeNode* root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int left=max(0,maxPath(root->left,maxi));
        int right=max(0,maxPath(root->right,maxi));
        maxi=max(maxi,left+right+root->val);
        return root->val+max(left,right);
    }
};
