// Last updated: 4/24/2026, 10:11:12 PM
class Solution {
public:
    int preIdx = 0, postIdx = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preIdx >= preorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        // Construct the left subtree if the current node is not the postorder node
        if (root->val != postorder[postIdx]) {
            root->left = constructFromPrePost(preorder, postorder);
        }

        // Construct the right subtree if the current node is not the postorder node
        if (root->val != postorder[postIdx]) {
            root->right = constructFromPrePost(preorder, postorder);
        }

        // Move to the next postorder index
        postIdx++;

        return root;
    }
};
