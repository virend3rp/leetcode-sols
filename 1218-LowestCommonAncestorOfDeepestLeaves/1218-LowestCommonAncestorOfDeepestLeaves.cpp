// Last updated: 4/24/2026, 10:10:09 PM
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }

private:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto [leftDepth, leftLCA] = dfs(root->left);
        auto [rightDepth, rightLCA] = dfs(root->right);

        if (leftDepth == rightDepth) return {leftDepth + 1, root};
        return leftDepth > rightDepth ? pair{leftDepth + 1, leftLCA} : pair{rightDepth + 1, rightLCA};
    }
};
