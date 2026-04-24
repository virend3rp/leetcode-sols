// Last updated: 4/24/2026, 10:13:58 PM
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
    vector<string> final;
    void TreePaths(TreeNode* root,string temp){
        if(root->left==NULL && root->right==NULL){
            temp+=to_string(root->val);
            final.push_back(temp);
        }
        temp+=to_string(root->val);
        if(root->left){
            TreePaths(root->left,temp+"->");
        }
        if(root->right){
        TreePaths(root->right,temp+"->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        TreePaths(root,"");
        return final;
    }
};