// Last updated: 4/24/2026, 10:15:16 PM
class Solution {
public:
    void solve(vector <int> &ans,TreeNode* root){
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        solve(ans,root->left);
        solve(ans,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;
        solve(ans,root);
        return ans;
    }
};