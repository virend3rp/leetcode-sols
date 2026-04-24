// Last updated: 4/24/2026, 10:15:56 PM
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        int count=0;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            if(count%2==1){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            count++;
        }
        return ans;
    }
};