// Last updated: 4/24/2026, 10:04:30 PM
class Solution {
public:
    vector<int> LargestPerfectSubtree(TreeNode* root) {
        vector<int> perfectSubtreeSizes;  
        isPerfectSubtree(root, perfectSubtreeSizes); 
        return perfectSubtreeSizes;
    }
    pair<bool, int> isPerfectSubtree(TreeNode* node, vector<int>& perfectSubtreeSizes) {
        if (node == NULL) {
            return {true, 0}; 
        }
        auto leftInfo = isPerfectSubtree(node->left, perfectSubtreeSizes);
        auto rightInfo = isPerfectSubtree(node->right, perfectSubtreeSizes);
        if (leftInfo.first && rightInfo.first && leftInfo.second == rightInfo.second) {
            int subtreeSize = leftInfo.second + rightInfo.second + 1;  
            perfectSubtreeSizes.push_back(subtreeSize);  
            return {true, subtreeSize};  
        }
        return {false, max(leftInfo.second, rightInfo.second) + 1};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> perfectSubtreeSizes = LargestPerfectSubtree(root);
        if (perfectSubtreeSizes.empty()) {
            return -1;
        }
        sort(perfectSubtreeSizes.rbegin(), perfectSubtreeSizes.rend());
        if (k <= perfectSubtreeSizes.size()) {
            return perfectSubtreeSizes[k - 1];
        } else {
            return -1;  
        }
    }
};
