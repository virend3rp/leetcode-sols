// Last updated: 4/29/2026, 5:42:38 PM
1class Solution {
2    void inorder(TreeNode* node, vector<int>& v) {
3        if (!node) return;
4        inorder(node->left, v);
5        v.push_back(node->val);
6        inorder(node->right, v);
7    }
8public:
9    bool findTarget(TreeNode* root, int k) {
10        vector<int> v;
11        inorder(root, v);
12        int l = 0, r = v.size() - 1;
13        while (l < r) {
14            int sum = v[l] + v[r];
15            if (sum == k) return true;
16            sum < k ? l++ : r--;
17        }
18        return false;
19    }
20};