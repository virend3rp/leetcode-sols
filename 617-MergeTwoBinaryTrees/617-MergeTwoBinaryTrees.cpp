// Last updated: 4/24/2026, 10:12:14 PM
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;

        int val = 0;
        // TreeNode* newLeft = nullptr;
        // TreeNode* newRight = nullptr;

        if (root1) val += root1->val;
        if (root2) val += root2->val;

        TreeNode* merged = new TreeNode(val);
        merged->left = mergeTrees(root1 ? root1->left : nullptr,
                                  root2 ? root2->left : nullptr);
        merged->right = mergeTrees(root1 ? root1->right : nullptr,
                                   root2 ? root2->right : nullptr);

        return merged;
    }
};
