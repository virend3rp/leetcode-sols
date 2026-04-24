// Last updated: 4/24/2026, 10:15:52 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* createTree(vector<int>& nums,int start,int end){
        if(end-start<0) return NULL;
        if(end-start == 0) return new TreeNode(nums[start]);
        return new TreeNode(nums[(start+end)/2],
            createTree(nums,start,(start+end)/2-1),
            createTree(nums,(start+end)/2+1,end));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
};