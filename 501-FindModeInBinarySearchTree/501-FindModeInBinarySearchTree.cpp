// Last updated: 4/24/2026, 10:12:45 PM
class Solution {
private:
    int currentVal;
    int currentCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void handleValue(int val) {
        if (val != currentVal) {
            currentVal = val;
            currentCount = 0;
        }
        currentCount++;

        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes.clear();
            modes.push_back(val);
        } else if (currentCount == maxCount) {
            modes.push_back(val);
        }
    }

    void inOrder(TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        handleValue(node->val);
        inOrder(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return modes;
    }
};
