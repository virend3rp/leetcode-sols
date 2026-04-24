// Last updated: 4/24/2026, 10:10:12 PM

class Solution {
public:
     TreeNode* solve(TreeNode* root,vector<TreeNode*>& final, unordered_set<int> searchSet){
        if(root==NULL){
            return NULL;
        }
        root->left=solve(root->left,final,searchSet);
        root->right=solve(root->right,final,searchSet);
        if(searchSet.count(root->val)){
                if (root->left) final.push_back(root->left);
                if (root->right) final.push_back(root->right);
                return nullptr; // Remove the current node
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> final; 
        unordered_set<int> searchSet(to_delete.begin(), to_delete.end());
        if(!searchSet.count(root->val)){
                final.push_back(root);
        }
        root=solve(root,final,searchSet);
        return final;
    }
};