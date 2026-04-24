// Last updated: 4/24/2026, 10:16:00 PM
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&& q!=NULL) return false;
        else if(q==NULL && p!=NULL) return false;
        else if(q==NULL && p==NULL) return true;
        if(p->val==q->val)
        {
            return isSameTree(p->left,q->left)&& isSameTree(p->right,q->right);
        }
        return false;
    }
};