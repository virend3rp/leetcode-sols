// Last updated: 4/24/2026, 10:14:07 PM
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val >= p->val && root->val <= q->val){
            return root;
        }
        else if(root->val <= p->val && root->val >= q->val){
            return root;
        }
        else if(root->val >= p->val && root->val >= q->val){
            root=lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val <= p->val && root->val <= q->val){
            root=lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};