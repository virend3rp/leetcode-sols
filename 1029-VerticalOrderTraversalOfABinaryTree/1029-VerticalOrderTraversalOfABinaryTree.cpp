// Last updated: 4/24/2026, 10:10:51 PM
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // To store the result
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        // Map to store nodes sorted by (vertical, level) -> list of nodes at that position
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue to store {node, {vertical, level}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  // Initial vertical and level are both 0

        // Perform BFS traversal
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            // Insert the node into map based on its vertical and level
            nodes[vertical][level].insert(node->val);

            // Traverse the left and right children
            if (node->left) {
                q.push({node->left, {vertical - 1, level + 1}});
            }
            if (node->right) {
                q.push({node->right, {vertical + 1, level + 1}});
            }
        }

        // Traverse the map and construct the answer
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};