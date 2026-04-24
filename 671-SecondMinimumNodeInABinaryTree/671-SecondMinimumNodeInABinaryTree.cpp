// Last updated: 4/24/2026, 10:12:03 PM
class Solution {
public:
    int rootVal;
    long ans=LONG_MAX;
    void solve(TreeNode* root){
        if(!root) return;

        if(root->val>rootVal && root->val<ans){
            ans=root->val;
        } else if(rootVal==root->val){
            solve(root->left);
            solve(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        rootVal=root->val;
        solve(root);
        return ans==LONG_MAX?-1:(int)ans;
    }
};