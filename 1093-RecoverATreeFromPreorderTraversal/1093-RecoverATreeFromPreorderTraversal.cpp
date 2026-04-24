// Last updated: 4/24/2026, 10:10:31 PM
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> arr; // (level, value) pairs
        int level = 0, num = 0;
        bool hasNum = false; // To track if we are building a number

        for (int i = 0; i < traversal.size(); i++) {
            if (traversal[i] == '-') {
                if (hasNum) {
                    arr.push_back({level, num});
                    num = 0;
                    hasNum = false;
                }
                level++;
            } else {
                num = num * 10 + (traversal[i] - '0');
                hasNum = true;
                if (i + 1 == traversal.size() || traversal[i + 1] == '-') {
                    arr.push_back({level, num});
                    num = 0;
                    hasNum = false;
                    level = 0;
                }
            }
        }

        TreeNode* root = new TreeNode(arr[0].second);
        map<int, TreeNode*> mp;
        mp[0] = root;

        for (int i = 1; i < arr.size(); i++) {
            int parentLevel = arr[i].first - 1;
            TreeNode* node = new TreeNode(arr[i].second);
            mp[arr[i].first] = node;

            if (!mp[parentLevel]->left) {
                mp[parentLevel]->left = node;
            } else {
                mp[parentLevel]->right = node;
            }
        }
        
        return root;
    }
};
