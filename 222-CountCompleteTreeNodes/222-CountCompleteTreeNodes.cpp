// Last updated: 4/24/2026, 10:14:18 PM
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int left=countNodes(root->left);
        int right=countNodes(root->right);

        return 1+left+right;
    }
};