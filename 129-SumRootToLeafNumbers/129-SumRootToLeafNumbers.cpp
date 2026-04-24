// Last updated: 4/24/2026, 10:15:29 PM
class Solution {
public:
  
    void SumRootToLeaf(TreeNode* root,int c_num,int& total_sum){
        if(root->left == nullptr && root->right == nullptr){
            total_sum += c_num * 10 + root->val;
            return;
        }
        if (root->left)
            SumRootToLeaf(root->left, c_num * 10 + root->val, total_sum);        
        if (root->right)
            SumRootToLeaf(root->right, c_num * 10 + root->val, total_sum);
    }

    int sumNumbers(TreeNode* root) {

        int total_sum = 0;
        SumRootToLeaf(root, 0, total_sum);
        return total_sum;
    }


};